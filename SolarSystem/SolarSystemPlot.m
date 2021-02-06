
%plots data from solarsystem.cpp

data = load('system.txt');
a = data(:,1);
b = data(:,2);
c = data(:,4);
d = data(:,5);
%e = data(:,7);
%f = data(:,8);
%g = data(:,10);
%h = data(:,11);
%i = data(:,13);
%j = data(:,14);
%k = data(:,16);
%l = data(:,17);
plot(a, b, 'ro', c, d, 'bo');

%, c, d, 'bo', e, f, 'go', g, h, 'yo', i, j, 'mo', k, l, 'ko'