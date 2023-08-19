# test di ipotesi su mu

# testi su lezione EpsA_9dic22

### 9.10
## nel dataset stud.recs c'è la variabile sat.m che contiene i risultati di 
## matematica degli studenti.
## testare l'hp nulla che la media del punteggio sia 500 contro una alterativa
## two-sided.
## Accetti o rifiuti con livello di significabilità pari a 0.05?

# H_0: mu = 500
# two sided -> H_1: mu != 500
# alpha = 0.05 -> rifiuto se p-value < alpha

data("stud.recs")

t.test(stud.recs$sat.m, alternative = "two.sided", mu = 500)

# p-value = 0.011 
#         < alpha ---> rifiuto H_0 a favore di H_1
# non posso affermare che mu = 500 ma devo dire che mu != 500

################################################################################
### 9.14
## nel dataset normtemp, la variabile temperature contiene normal body temperature
## I dati sembrano derivare da una normal distribution?
## Fare un t-test per vedere se il valore comunemente assunto di 90.6°F è corretto.
## Alcuni studi dicono che è più accurata 98.2°F

data("normtemp")

# dato che n è grande (130) posso dire che è normale

#trasformo in celsius
tempcelsius <- (normtemp$temperature - 32)/1.8
mu <- (98.6-32)/1.8

# H_0: mu = 37
# H_1: mu < 37

t.test(tempcelsius, alternative = "less", mu = 37)

# p-value = 1.2053 * 10^(-7) = 0 (alla 4° cifra decimale)

# il testo non mi dà alpha !!
# ma p è MOLTO piccolo, quindi posso dire che p < alpha
# ---> rifiuto H_0 a favore di H_1

# posso affermare che c'è sufficiente evidenza statistica per dire che la
# temperatura media corporea è < 37°

################################################################################
### 9.3
## viene testato un nuovo farmaco con la seguente prestazione:
## dei 50 pazienti dello studio, 40 non ricadono nella malattia dopo 18 mesi.
## senza terapia, la percentuale attesa di non ricaduta è del 75%.
## i dati supportano l'idea che l'ipotesi che questa percentuale sia aumentata (con terapia)?
## quanto vale p-value ?

# devo fare un test sulle proporzioni (probabilità -> binom)
# H_0: p = 0.75 --> probabilità di non ricaduta senza terapia
# p1 = 4/5 = 0.8 (alternativa = p maggiore)
# H_1: p > 0.75 

binom.test(40, 50, alternative = "greater", p = 0.75)

# p-value = 0.2622
# posso affermare che la terapia ha aumentato la prob di non ricadere nella malattia?
# supponiamo alpha = 0.05
# p-value < alpha ? NO ---> non rifiuto H_0
# --> non posso affermare che il nuovo farmaco sia efficace

################################################################################
### 9.31
## nel dataset babies la variabile age contiene età delle madri e dage contiene 
## età dei padri. Fare un test di ipotesi sulla differenza di medie con l'ipotesi
## di "stessa età" contro la one-sided alternative che i padri siano più vecchi.

# H_0: mu_m - mu_d = 0
# H_1: mu_m - mu_d < 0 (madri più giovani)
# sono appaiati o indipendenti? appaiati (stanno sulla stessa riga)

data(babies)

t.test(babies$age, babies$dage, alternative = "less", mu = 0, paired = TRUE)

# p-value < 2.220446049e-16 MOLTO PICCOLO
# rifiuto H_0 a favore di H_1
# -->> c'è sufficiente evidenza statistica per dire che mediamente i padri sono
#       più vecchi delle madri.

################################################################################
### FARE DA SOLA 9.7 E 3.36 ###
################################################################################