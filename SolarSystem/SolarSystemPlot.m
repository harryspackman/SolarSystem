
%plots data from solarsystem.cpp

data = load('system1.txt');
a = data(:,1);
b = data(:,2);
c = data(:,4);
d = data(:,5);
e = data(:,7);
f = data(:,8);
g = data(:,10);
h = data(:,11);
i = data(:,13);
j = data(:,14);

plot(a, b, 'ro', c, d, 'go' ,e, f, 'bo', c, d, 'bo', e, f, 'go', g, h, 'yo', i, j, 'mo');

%, c, d, 'bo', e, f, 'go', g, h, 'yo', i, j, 'mo', k, l, 'ko'