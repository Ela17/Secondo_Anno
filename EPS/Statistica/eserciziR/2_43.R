data("nym.2002")
str(nym.2002)

hist(nym.2002$time)
summary(nym.2002$time)

# 3h = 180 min

abline(v = 180, col = "red")

#calcolo quente sono le osservazioni <= 180
nym.2002$time[nym.2002$time <= 180] -> veloci
length(veloci)
#percentuale:
length(veloci)/length(nym.2002$time)

options(digits = 10) #visualizzo 10 cifre dopo la virgola

#per essere nel top 10% quanto devi essere veloce? e per il 25%?
#10%: decimo percentile
quantile(nym.2002$time, 0.1)
#25%: 25esimo percentile
quantile(nym.2002$time, 0.25)

#che tempi ha il peggior 10% ?
# peggior 10% == miglior 90%
quantile(nym.2002$time, 0.9)
