rm(list=ls())

## legge dei grandi numeri sulla media

N <- 10
dati <- rexp(N,2)

media10 <- mean(dati)

N <- 30
dati <- rexp(N,2)

media30 <- mean(dati)

N <- 100
dati <- rexp(N,2)

media100 <- mean(dati)

N <- 1000
dati <- rexp(N,2)

media1000 <- mean(dati)

N <- 10000
dati <- rexp(N,2)

media10000 <- mean(dati)


plot(c(10,30,100,1000,10000),c(media10,media30,media100,media1000,media10000))
abline(h=0.5,col="red")

### ne lancio tanti
N <- seq(5,10^4,10)
trueMedia <- 4
medie <- numeric(length(N))
posizione <- 1
for (indice in N){
  medie[posizione] <- mean(rexp(indice,1/trueMedia))
  posizione <- posizione + 1
}
plot(N,medie,type="l")
abline(h=trueMedia,col="red")
###tanti di più
N <- seq(5,10^5,100)
trueMedia <- 4
medie <- numeric(length(N))
posizione <- 1
for (indice in N){
  medie[posizione] <- mean(rexp(indice,1/trueMedia))
  posizione <- posizione + 1
}
plot(N,medie,type="l")
abline(h=trueMedia,col="red")

# l'oscillazione si "schiaccia" sempre di più alla media aumentando il campione

## stessa cosa per la varianza campionaria

###tanti
N <- seq(5,10^4,10)
trueMedia <- 4
p <- 1/trueMedia
trueVar <- 1/(p^2)
varianze <- numeric(length(N))
posizione <- 1
for (indice in N){
  varianze[posizione] <- var(rexp(indice,1/trueMedia))
  posizione <- posizione + 1
}
plot(N,varianze,type="l")
abline(h=trueVar,col="red")