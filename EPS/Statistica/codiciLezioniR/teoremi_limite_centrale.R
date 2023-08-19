
# teorema del limite centrale

## parto da una distribuzione exp
R <- 1000 # quanti campioni casuali di taglia N genero
N <- 1000 # dimensione del campione casuale
trueMedia <- 2
p <- 1/trueMedia
trueSD <- 1/p

# genero un insieme di campioni casuali di taglia N
dati <- matrix(nrow = N, ncol = R)
medie <- numeric(R)
for (indice in 1:R){
  dati[,indice] <- rexp(N,p)
  medie[indice] <- mean(dati[,indice])
}

hist(medie)

## parto da una distribuzione binomiale
trueMedia <- 0.9
p <- 1/trueMedia
trueSD <- sqrt(trueMedia*(1-trueMedia))

dati <- matrix(nrow = N, ncol = R)
medie <- numeric(R)
for (indice in 1:R){
  dati[,indice] <- rbinom(N,1,trueMedia)
  medie[indice] <- mean(dati[,indice])
}

hist(medie)

# la normale N(0,1)

x <- seq(min(medie), max(medie), 0.001)
mediaNormale <- trueMedia
sdNormale <- trueSD/sqrt(N)
hist(medie,freq = FALSE)
lines(x,dnorm(x,mean = mediaNormale, sd = sdNormale),col="red")