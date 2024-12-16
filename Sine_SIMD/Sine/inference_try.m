clc;
close all;
clear all;
sw1=0.003982725087553263;
sb1=0.00009808481263462454;
sw2=0.012466593645513058;
sb2=0.00012682360829785466;
sw3=0.017348935827612877;
sb3=0.00009529944509267807;
sa0=0.02462756261229515;
sa1=0.010173075832426548; 
sa2=0.005493100266903639;
net = importKerasNetwork('sine.hdf5');
%analyzeNetwork(net)
%Extract Theta1 from the net
w1=net.Layers(2,1).Weights;
b1=net.Layers(2,1).Bias;
wq1=round(w1./sw1);
bq1=round(b1./sb1);
fileID1 = fopen('wq1_int8.txt','w');
for i=1:size(wq1,1)
    for j=1:size(wq1,2)
fprintf(fileID1,'%d,',int8(wq1(i,j)));
    end
    fprintf(fileID1,'\n');
end
fclose(fileID1);

fileID1 = fopen('bq1_int8.txt','w');
for i=1:size(bq1,1)
    fprintf(fileID1,'%d,',int32(bq1(i)));
end
fclose(fileID1);
%Extract Theta2 from the net
w2=net.Layers(4,1).Weights;
b2=net.Layers(4,1).Bias;
wq2=round(w2./sw2);
bq2=round(b2./sb2);
fileID1 = fopen('wq2_int8.txt','w');
for i=1:size(wq2,1)
    for j=1:size(wq2,2)
fprintf(fileID1,'%d,',int8(wq2(i,j)));
    end
    fprintf(fileID1,'\n');
end
fclose(fileID1);

fileID1 = fopen('bq2_int8.txt','w');
for i=1:size(bq2,1)
    fprintf(fileID1,'%d,',int32(bq2(i)));
end
fclose(fileID1);
%%Extract Theta3 from the net
w3=net.Layers(6,1).Weights;
b3=net.Layers(6,1).Bias;
wq3=round(w3./sw3);
bq3=round(b3./sb3);
fileID1 = fopen('wq3_int8.txt','w');
for i=1:size(wq3,1)
    for j=1:size(wq3,2)
fprintf(fileID1,'%d,',int8(wq3(i,j)));
    end
    fprintf(fileID1,'\n');
end
fclose(fileID1);

fileID1 = fopen('bq3_int8.txt','w');
for i=1:size(bq3,1)
    fprintf(fileID1,'%d,',int32(bq3(i)));
end
fclose(fileID1);

%Predict
X=single((2*pi)*rand(1000,1));
Xq=round(X./sa0);
for i=1:1000
%[p1 g1]= digit_FC(b1,w1,6.28);
[p1 g1]= digit_FC(b1,w1,X(i));
C_1(i)=max(g1);
[pq1 gq1]= digit_FC(bq1,wq1,Xq(i));
gq1_8=round(gq1*(sb1/sa1));
[p2 g2]= digit_FC(b2,w2,g1);
C_2(i)=max(g2);
[pq2 gq2]= digit_FC(bq2,wq2,gq1_8);
gq2_8=round(gq2*(sb2/sa2));
[p3(i) g3]= digit_FC(b3,w3,g2);
[pq3(i) gq3]= digit_FC(bq3,wq3,gq2_8);
end
pq_f32=pq3*sb3;
figure(1)
stem(X,p3);
figure(2)
stem(X,pq_f32);
Xin=X(10);
YPred = predict(net,Xin);
[p3' pq_f32']