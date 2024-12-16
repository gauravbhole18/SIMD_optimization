function p = predict_sine(Theta1, Theta2,Theta3, X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)


X = [1; X];
w1=Theta1*X;
%ReLU function
g1=max(w1,0);

a1 = [1; g1];

w2=Theta2*a1;
g2=max(w2,0);
a2=[1;g2];
p=Theta3*a2;

% =========================================================================


end