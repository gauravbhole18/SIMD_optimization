clc;
close all;
clear all;
load digit8000_Optimized.mat;
load filterBank8000.mat;
%analyzeNetwork(trainedNet)
%Input Layer Details
n_L=trainedNet.Layers(1,1).InputSize;
%Convolution Layer1 Details
n_C1=trainedNet.Layers(2,1).NumChannels;
f1=trainedNet.Layers(2,1).FilterSize;
S1=trainedNet.Layers(2,1).Stride;
padmode1=trainedNet.Layers(2,1).PaddingMode;
pad1=trainedNet.Layers(2,1).PaddingSize;
W1=trainedNet.Layers(2,1).Weights;
b1=trainedNet.Layers(2,1).Bias;
%Weight
fileID1 = fopen('W_1.txt','w');
for i=1:size(W1,4)
     fprintf(fileID1,'\n');
    weight=W1(:,:,:,i);
    for j=1:size(W1,3)
        
    weight1=weight(:,:,j);
    for k=1:size(W1,2)
        for l=1:size(W1,1)
          fprintf(fileID1,'%f,',single(weight1(k,l)));  
        end
         fprintf(fileID1,'\n');
    end
        end
   
    
end
fclose(fileID1);
%bias
fileID1 = fopen('b_1.txt','w');
for i=1:size(b1,3)
    fprintf(fileID1,'%f,',single(b1(:,:,i)));
end
fclose(fileID1);
%Convolution Layer2 Details
n_C2=trainedNet.Layers(5,1).NumChannels;
f2=trainedNet.Layers(5,1).FilterSize;
S2=trainedNet.Layers(5,1).Stride;
padmode2=trainedNet.Layers(5,1).PaddingMode;
pad2=trainedNet.Layers(5,1).PaddingSize;
W2=trainedNet.Layers(5,1).Weights;
b2=trainedNet.Layers(5,1).Bias;
%Weight
fileID1 = fopen('W_2.txt','w');
for i=1:size(W2,4)
     fprintf(fileID1,'\n');
    weight=W2(:,:,:,i);
    for j=1:size(W2,3)
        
    weight1=weight(:,:,j);
    for k=1:size(W2,2)
        for l=1:size(W2,1)
          fprintf(fileID1,'%f,',single(weight1(k,l)));  
        end
         fprintf(fileID1,'\n');
    end
        end
   
    
end
fclose(fileID1);
%bias
fileID1 = fopen('b_2.txt','w');
for i=1:size(b2,3)
    fprintf(fileID1,'%f,',single(b2(:,:,i)));
end
fclose(fileID1);
%Convolution Layer3 Details
n_C3=trainedNet.Layers(8,1).NumChannels;
f3=trainedNet.Layers(8,1).FilterSize;
S3=trainedNet.Layers(8,1).Stride;
padmode3=trainedNet.Layers(8,1).PaddingMode;
pad3=trainedNet.Layers(8,1).PaddingSize;
W3=trainedNet.Layers(8,1).Weights;
b3=trainedNet.Layers(8,1).Bias;
%Convolution Layer4 Details
n_C4=trainedNet.Layers(11,1).NumChannels;
f4=trainedNet.Layers(11,1).FilterSize;
S4=trainedNet.Layers(11,1).Stride;
padmode4=trainedNet.Layers(11,1).PaddingMode;
pad4=trainedNet.Layers(11,1).PaddingSize;
W4=trainedNet.Layers(11,1).Weights;
b4=trainedNet.Layers(11,1).Bias;
%Extract Theta1 from the net
wf1=trainedNet.Layers(15,1).Weights;
bf1=trainedNet.Layers(15,1).Bias;
Theta1=[bf1 wf1];
%Input Processing
epsil = 1e-6;
[x, fs]=audioread('E:\Research\CNN_Quantization_Paper1\VoiceActivityDetection - Copy\speech_commands_v0.01\six\0b09edd3_nohash_3.wav');
x = downsample(x,2);
fs=8000;
N = 240;
hopLength = 160;
fftLength=256;
% Buffer into frames.
y = audio.internal.buffer(x,N,hopLength);
Y = fft(y,fftLength,1);
Y = abs(Y);
Y = Y.^2;
P = filterBank.' * Y;
XTest=log10(P + epsil);
mean=trainedNet.Layers(1,1).AverageImage;
XTest=XTest-mean;
%--------------------------------------------------------------------------
XTest=single(XTest);
fileID1 = fopen('XTest.txt','w');
for i=1:size(XTest,1)
    for j=1:size(XTest,2)
fprintf(fileID1,'%f,',XTest(i,j));
    end
    fprintf(fileID1,'\n');
end
fclose(fileID1);
%--------------------------------------------------------------------------
Qa0=(127/ceil(max(max(XTest))));
XTest_int8=round(XTest.*Qa0);
%Convolution Layer 1
%----------------------------------------------------------------------------
padd='both';
Qw1=(127/(ceil(max(max(max(max(W1)))))));
W1_int8=round(W1.*Qw1);
b1_int8=round(b1.*(Qa0*Qw1));%bi_int8 is 32 bit storage
conv1_out=conv_infer(XTest,W1,b1,pad1,S1,padd);
conv1_out_int8=conv_infer(XTest_int8,W1_int8,b1_int8,pad1,S1,padd);
%Relu
conv1_out_relu=max(conv1_out,0);
fileID1 = fopen('maxpool.txt','w');
for i=1:size(conv1_out_relu,3)
     fprintf(fileID1,'\n');
    weight=conv1_out_relu(:,:,i);
        for k=1:size(conv1_out_relu,1)
        for l=1:size(conv1_out_relu,2)
          fprintf(fileID1,'%f,',single(weight(k,l)));  
        end
         fprintf(fileID1,'\n');
    end
        end
conv1_out_relu_int8=max(conv1_out_int8,0);
%MaxPooling
padd='both';
f_pool1=trainedNet.Layers(4,1).PoolSize;
S_pool1=trainedNet.Layers(4,1).Stride;
Mpad1=trainedNet.Layers(4,1).PaddingSize;
conv1_out_relu=zero_pad(conv1_out_relu,Mpad1(2),padd);
conv1_out_relu_int8=zero_pad(conv1_out_relu_int8,Mpad1(2),padd);
conv1_out_relu=conv1_out_relu([2:42],:,:);
conv1_out_relu_int8=conv1_out_relu_int8([2:42],:,:);
max_pool1=pool_infer(conv1_out_relu,f_pool1,S_pool1);
max_pool1_int8=pool_infer(conv1_out_relu_int8,f_pool1,S_pool1);

%Convolution Layer 2
%Re-Quantization
Qa1=(127/ceil(max(max(max(max_pool1)))));
max_pool1_int8_a1=round(max_pool1_int8.*(Qa1/(Qa0*Qw1)));
%----------------------------------------------------------------------------
padd='both';
Qw2=(127/(ceil(max(max(max(max(W2)))))));
W2_int8=round(W2.*Qw2);
b2_int8=round(b2.*(Qa1*Qw2));
conv2_out=conv_infer(max_pool1,W2,b2,pad2,S2,padd);
conv2_out_int8=conv_infer(max_pool1_int8_a1,W2_int8,b2_int8,pad2,S2,padd);
%Relu
conv2_out_relu=max(conv2_out,0);
conv2_out_relu_int8=max(conv2_out_int8,0);
%MaxPooling
padd='both';
f_pool2=trainedNet.Layers(7,1).PoolSize;
S_pool2=trainedNet.Layers(7,1).Stride;
Mpad2=trainedNet.Layers(7,1).PaddingSize;
conv2_out_relu=zero_pad(conv2_out_relu,Mpad2(2),padd);
conv2_out_relu_int8=zero_pad(conv2_out_relu_int8,Mpad2(2),padd);
conv2_out_relu=conv2_out_relu([2:22],:,:);
conv2_out_relu_int8=conv2_out_relu_int8([2:22],:,:);
max_pool2=pool_infer(conv2_out_relu,f_pool2,S_pool2);
max_pool2_int8=pool_infer(conv2_out_relu_int8,f_pool2,S_pool2);
%Convolution Layer 3
%----------------------------------------------------------------------------
%Re-Quantization
Qa2=(127/ceil(max(max(max(max_pool2)))));
max_pool2_int8_a2=round(max_pool2_int8.*(Qa2/(Qa1*Qw2)));
padd='both';
Qw3=(127/(ceil(max(max(max(max(W3)))))));
W3_int8=round(W3.*Qw3);
b3_int8=round(b3.*(Qa2*Qw3));
conv3_out=conv_infer(max_pool2,W3,b3,pad3,S3,padd);
conv3_out_int8=conv_infer(max_pool2_int8_a2,W3_int8,b3_int8,pad3,S3,padd);
%Relu
conv3_out_relu=max(conv3_out,0);
conv3_out_relu_int8=max(conv3_out_int8,0);
%MaxPooling
padd='both';
f_pool3=trainedNet.Layers(10,1).PoolSize;
S_pool3=trainedNet.Layers(10,1).Stride;
Mpad3=trainedNet.Layers(10,1).PaddingSize;
conv3_out_relu=zero_pad(conv3_out_relu,Mpad3(2),padd);
conv3_out_relu_int8=zero_pad(conv3_out_relu_int8,Mpad3(2),padd);
conv3_out_relu=conv3_out_relu([2:12],:,:);
conv3_out_relu_int8=conv3_out_relu_int8([2:12],:,:);
max_pool3=pool_infer(conv3_out_relu,f_pool3,S_pool3);
max_pool3_int8=pool_infer(conv3_out_relu_int8,f_pool3,S_pool3);
%Convolution Layer 4
%----------------------------------------------------------------------------
%Re-Quantization
Qa3=(127/ceil(max(max(max(max_pool3)))));
max_pool3_int8_a3=round(max_pool3_int8.*(Qa3/(Qa2*Qw3)));
padd='both';
Qw4=(127/(ceil(max(max(max(max(W4)))))));
W4_int8=round(W4.*Qw4);
b4_int8=round(b4.*(Qa3*Qw4));
conv4_out=conv_infer(max_pool3,W4,b4,pad4,S4,padd);
conv4_out_int8=conv_infer(max_pool3_int8_a3,W4_int8,b4_int8,pad4,S4,padd);
%Relu
conv4_out_relu=max(conv4_out,0);
conv4_out_relu_int8=max(conv4_out_int8,0);
%MaxPooling
padd='both';
f_pool4=trainedNet.Layers(13,1).PoolSize;
S_pool4=trainedNet.Layers(13,1).Stride;
Mpad4=trainedNet.Layers(13,1).PaddingSize;
%Nopadding required for this layer
max_pool4=pool_infer(conv4_out_relu,f_pool4,S_pool4);
max_pool4_int8=pool_infer(conv4_out_relu_int8,f_pool4,S_pool4);
%----------------------------------------------------------------------------
%Fully Connected Layer
%----------------------------------------------------------------------------
%Qa4=(127/ceil(max(max(max(max_pool4)))));
Qa4=128/8;
max_pool4_int8_a4=round(max_pool4_int8.*(Qa4/(Qa3*Qw4)));
max_poolT=permute(max_pool4,[1 2 3]);
max_poolT_int8=permute(max_pool4_int8_a4,[1 2 3]);
X=max_poolT(:);
X_int8=max_poolT_int8(:);
QF1=(128/(ceil((max(max(wf1))))));
WF1_int8=round(wf1.*QF1);
BF1_int8=round(bf1.*(Qa4*QF1));
Theta1_int8=[BF1_int8 WF1_int8];
%Theta1_IT=Theta1_I';
%WF1_int8T=WF1_int8';
fileID1 = fopen('WF1_int8.txt','w');
for i=1:size(WF1_int8,1)
    for j=1:size(WF1_int8,2)
fprintf(fileID1,'%d,',WF1_int8(i,j));
    end
    fprintf(fileID1,'\n');
end
fclose(fileID1);

pred= digit_FC(bf1,wf1,X);
pred_int8= digit_FC(BF1_int8,WF1_int8,X_int8);
pred_int81=pred_int8/(Qa4*QF1);
m = max(pred);
m_int8= max(pred_int81);
e = exp(pred-m);
e_int8 = exp(pred-m_int8);
dist = e /sum(e);
dist_int8 = e_int8 /sum(e_int8);
[score idx]=max(dist);
[score_int8 idx_int8]=max(dist_int8);
classes=trainedNet.Layers(17,1).Classes;
digit=classes(idx)
digit_int8=classes(idx_int8)

