## 1
p1 <- 5/13
p2 <- dbinom(2,2,5/13) + dbinom(2,2,8/13)
p3 <- 1 - dbinom(0,2,5/13)
p4 <- dbinom(1,1,5/13)
p5 <- dbinom(1,1,8/13)


## 2
p1 <- 10/14
p2 <- dhyper(3, 4, 10, 3) + dhyper(3, 10, 4, 3)
p3 <- 1 - dhyper(0, 10, 3, 3)
p4 <- dbinom(1,1,p1)
p5 <- 9/13*4/12 + 4/13*9/12


## 3
prob <- 8/(8+9) # prob di estrarre giallo
p1 <- dgeom(4, prob) # prob di fare esattamente 4 estraz prima del successo
p2 <- 1 - pgeom(3, prob) # prob di fare almeno 5 estrazioni
# dado a 5 facce equo
p3 <- 1/5
p4 <- 1/7+1/7


## 4
p1 <- (1-0.75)*0.5 + (1-0.03)*0.5
p2 <- (1-0.03)*0.5/p1
p3 <- 0.03*0.5/(1-p1)


## 5
p1 <- pgeom(7,0.25)
p2 <- pgeom(1,0.25)
prob <- 0.25*(1-0.73) + 0.69*0.73
p3 <- pgeom(7, prob)


## 6
# Poisson
k <- 15/7
mediaCasa <- 7*k
mediaMare <- 4*k
c <- 0.77
m <- 1 - c
x <- 11

p1 <- 1 - ppois(x-1, mediaMare)

p2 <- (1 - ppois(x-1, mediaCasa))*c + p1*m

pmare <- ppois(x-1, mediaMare)
pcasa <- ppois(x-1, mediaCasa)
p3 <- (pcasa*c + pmare*m)*c

# p3 non torna


## 7
n <- 9
paffitto <- 0.61
ppromo <- 0.08
#indipendenza --> binom

p1 <- 1 - pbinom(n%/%2, n, paffitto)

p2 <- 1 - pbinom(n%/%2, n, paffitto+ppromo)

guadagnoAttuale <- 125*n*paffitto
guadagnoPromo <- 125*n*(paffitto+ppromo)
incremento <- guadagnoPromo - guadagnoAttuale


## 8
r <- 18
n <- 10
probr <- 18/28
probn <- 10/28

p1 <- dhyper(3, r, n, 3)

p2 <- p1

p3 <- 1*p1 + 2/3*dhyper(2,r,n,3) + 1/3*dhyper(1,r,n,3)


## 9
mediaS <- 5
mediaNS <- 2
# poisson
pS <- 254/365

p1 <- dpois(9, mediaS)

p2 <- 1 - ppois(8, mediaS)

p3 <- dpois(0,mediaS)*pS + dpois(0,mediaNS)*(1-pS) 

p4 <- dpois(0,mediaS) * pS / p3


## 10
# poisson di parametro 3
lambda <- 3

p1 <- 1 - ppois(1, lambda/2)

# 4 terr sapendo che ce ne sono stati almeno 2
p2 <- (1 - dpois(1, lambda/2)) * dpois(4, lambda)


## 11
media <- 2
varianza <- 9

ris1 <- varianza + media^2

ris2 <- ris1 - mean(7)

ris3 <- 3^2 * varianza

ris4 <- sqrt(ris3)


## 12

ris1 <- 1/12
ris2 <- 1/12 + 2/12 + 1/12
# indipend se ris1 == p(X=10)*p(Y=7)
pX10 <- 1/12+1/12+1/12+1/12
pY7 <- 1/12+1/12+2/12
pX10*pY7  # diverso da ris1