function [w1 g1] = digit_FC(bf1,wf1,X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)



%ReLU function

w1t=wf1*X;
w1=w1t+bf1;
g1=max(w1,0);


% =========================================================================


end