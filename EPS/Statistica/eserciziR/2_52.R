data("babyboom")

# calcolare la skewness della variabile wt che registra il peso alla nascita.
# questa variabile è simmetrica o asimmetrica?

#non c'è una funzione nel pacchetto base:
install.packages("moments")
library(moments)

# ora ho la funzione skewness

skewness(babyboom$wt)

# è negativa, quindi ho piu osservazioni minori della media (quindi verso sx)

#verifico con un istogramma
hist(babyboom$wt)

boxplot(babyboom$wt)
