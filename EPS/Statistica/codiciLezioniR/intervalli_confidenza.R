# PDF della t di Student

x <- seq(-10,10,0.01)
plot(x,dt(x,10), type = "l")
lines(x, dt(x,1), col = "red")
lines(x, dnorm(x,0,1), col = "blue")

#per n >= 30 è praticamente indistinguibile da N(0,1)

## intervalli_confidenza

alpha = 0.05

#t_alpha/2
qt(alpha/2,1)

#t_(1-alpha/2)
qt(1-alpha/2,1)

# effettivamente sono simmetrici

# aumento i gradi di libertà

#t_alpha/2
qt(alpha/2,30)

#t_(1-alpha/2)
qt(1-alpha/2,30)

## supponiamo di avere 10 osservazioni -> n-1 = 9

#t_alpha/2
qt(alpha/2,9)

#t_(1-alpha/2)
qt(1-alpha/2,9)

### FUNZIONE CHE CALCOLA IN AUTOMATICO 
### INTERVALLI DI CONFIDENZA
# t.test

library(UsingR)
data(babies)

t.test(babies$age, conf.level = 0.95)
