# testi e appunti alla lezione EpsA_2dic22

### 8.14
## stud.recs (UsingR) contiene math SAT scores nella variabile sat.m
## Trova l'intervallo di confidenza al 90% per la media di sat.m

library(UsingR)
data(stud.recs)

options(digits = 15) # 15 cifre dopo la virgola

# 90% --> 1-alpha = 0.9
ic <- t.test(stud.recs$sat.m, conf.level = 0.9)

str(ic) # è una lista di 10 argomenti
# arrotondo (a mano) alla 4° cifra decimale
ic$conf.int # [476.8953, 494.9797]

#####################################################################
### 8.18
## dataset normtemp contiene misurazioni di 130 healty
## variabile temperature contiene la temperatura corporea normale
## 1) I dati appaiono estratti da una distribuzione Normale?
## 2) Trovare l'intervallo di conf al 90% per la media normale della temperatura corporea.

# per prima cosa trasformo in gradi Celsius
data("normtemp")
tempcelsius <- (normtemp$temperature - 32)/1.8

# 1) per rispondere faccio l'istogramma
hist(tempcelsius)
# ha circa la forma di una campana, quindi potrebbe essere campionato da una normale

# 2)
# 1-alpha = 0.9 (90%)
t.test(tempcelsius, conf.level = 0.9) 
# media = 36.8051
# ic = [36.7459, 36.8643]

# perchè l'es chiedeva di controllare la normalità?
# se n piccolo (<= 30) l'approssimazione con t Student non è buona e devo ipotizzare che la popolaz sia normale e DEVO guardare l'istogramma
# se n grande (> 30) l'approssimazione va benissimo e nessun problema
# in questo problema ho 130 osservazioni quindi sono tranquilla

############################################################################################################################################
### 8.6
## uno studente vuole di trovare le proporzioni di persone mancine al suo college.
## intervista 100 studenti e trova che solo 5 lo sono.
## se computa al 95% l'ic, può contenere il valore p = 1/10 ?

# 1-alpha = 0.95
#posso chiamare la binom.test in due modi diversi:
# 1)
binom.test(5,100, conf.level = 0.95)
# 2)
binom.test(c(5,95), conf.level = 0.95)

# ic = [0.0164, 0.1128] contiene p = 1/10 = 0.1

#############################################################################################
### 8.9
## Una pubblicità affermava che "4 su 5 dentisti intervistati sono d'accordo a raccomandare Trident ai pazienti che voglio masticare gomme".
## Supponi che i risultati fossero calcolati su un Random Sample da tutta la popolazione dei dentisti.
## Calcola l'ic per la vera proporzione (al 90%) se la sample size è n=5.
## Ripeti con n = 100 e n = 1000

# proporzione campionaria = 4/5
samplep <- 4/5
n <- 5
binom.test(samplep*n, n, conf.level = 0.9)
# ic = [0.3426, 0.9898] per n = 5
# l'intervallo è molto grande! -> 4/5 non è una buona proporzione in realtà

n <- 100
binom.test(samplep*n, n, conf.level = 0.9)
# ic = [0.7228, 0.8633] per n = 100
# è meglio

n <- 1000
binom.test(samplep*n, n, conf.level = 0.9)
# ic = [0.7780, 0.8206] per n = 1000
# ancora meglio

# deduco che all'aumento di n l'ic si stringe
# la proporzione migliora

############################################################################
### GaltonFamilies(HistData)
## Il dataset contiene altezze e gender di 934 bambini. 
## Calcolare l'intervallo di confidenza (95%) per la differenza in altezza in base al gender.

library(HistData)
data("GaltonFamilies")
str(GaltonFamilies)
# 934 osservazioni di 8 variabili

# voglio capire se c'è una differenza di altezza per genere

# prima di fare l'ic disegnamo i boxplot
boxplot(GaltonFamilies$childHeight ~ GaltonFamilies$gender)
# la scatola delle femmine si trova a valori più bassi rispetto a quella dei maschi.
# quindi effettivamente ha senso calcolare l'ic
# vuole due parametri x e y e l'indicazione se sono indipendenti o appaiati
# in questo caso abbiamo campioni indipendenti (paired False) e devo passare altezze maschi e femmine

alt.m <- GaltonFamilies$childHeight[GaltonFamilies$gender == "male"]
alt.f <- GaltonFamilies$childHeight[GaltonFamilies$gender == "female"]
t.test(alt.m, alt.f, paired = FALSE, conf.level = 0.95)

# ic = [4.8103, 5.45]
# mean maschi = 69.2341
# mean femmine = 64.104
# l'intervallo è positivo perchè effettivamente i maschi sono più alti

# ATTENZIONE: se scambio i parametri x e y cambiano i segni!!!
# --> controllare bene l'ordine specificato nel testo

########################################################################
### 8.28
## nel dataset babies la variab age contiene età della madre e la variab dage l'età del padre.
## Calcolare l'ic al 95% per la differenza media dell'età.
## Contiene 0 ? Cosa si può assumere?

data(babies)
# 1236 osservaz di 23 variabili

# appaiati o indipendenti? appaiati! age e dage sono legati al bambino

plot(density(babies$age)$x, density(babies$age)$y, type  = "l")
lines(density(babies$dage)$x, density(babies$dage)$y, type  = "l", col = "blue")

# sembra che i padri siano generalmente più vecchi delle madri (linea blu più a dx)
# mi aspetto valori negativi facendo madre-padre

t.test(babies$age, babies$dage, paired = TRUE, conf.level = 0.95)
# effettivamente ho ic = [-3.7454, -2.986]
# differenza media = -3.3657

# dai valori ic osserviamo che non è compreso lo 0, quindi
# possiamo affermare che le coppie osservate non sono formate da coetanei 
# e che le madri sono decisamente più giovani dei padri.