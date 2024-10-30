csv_tab = csvread("ntc.csv");

t = csv_tab(:,1);
ad = csv_tab(:,2);

for i = 1 : length(csv_tab)
    ad(i) = ad(i) * 1024 / (ad(i) + 10);
end

plot(ad, t)


p = polyfit(ad, t, 10);
ad2 = 0:1023;
t2 = round(polyval(p, ad2), 1);
hold on, plot(ad2, t2, 'r');

dlmwrite('data.dlm', t2*10, ',');