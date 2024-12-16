clc;
close all;
clear all;

net = importKerasNetwork('sine.hdf5');
analyzeNetwork(net)
%Extract Theta1 from the net
w=net.Layers(2,1).Weights;
b=net.Layers(2,1).Bias;
Theta1=[b w];
%Extract Theta2 from the net
w=net.Layers(4,1).Weights;
b=net.Layers(4,1).Bias;
Theta2=[b w];
%%Extract Theta3 from the net
w=net.Layers(6,1).Weights;
b=net.Layers(6,1).Bias;
Theta3=[b w];
%Predict
X= 0;
X

pred = predict_sine(Theta1, Theta2, Theta3, X);

stem(X,pred)
Xin=X;
YPred = predict(net,Xin);