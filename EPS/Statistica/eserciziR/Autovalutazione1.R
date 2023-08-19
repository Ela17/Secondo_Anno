### Domanda 1

omega <- 7*7

# 1) E = "è stato estratto il numero 5"
P_E <- 13/omega

# 2) F = "la somma dei due numeri estratti è pari"
# F = {11, 13, 15, 17, 22, 24, 26, 33, 35, 37, 44, 46, 55, 57, 66, 77}
P_F <- 25/omega

# 3) G = "la somma dei due numeri estratti è dispari"
P_G = 1 - P_F

# 4) H = "il primo numero estratto è maggiore (>) del secondo"
tgH = sum(seq.int(1,6, 1))
P_H = tgH/omega

########################################################################
### domanda 2

omega = 7
casi_poss = factorial(omega)/(factorial(2)*factorial(omega-2))

# 1) E = "è stato estratto il numero 5"
P_E <-  6/casi_poss

# 2) F = "la somma dei due numeri estratti è pari"
P_F <- 3/omega*2/(omega-1) + 4/omega*3/(omega-1)

# 3) G = "la somma dei due numeri estratti è dispari"
P_G <- 4/omega*3/(omega-1) + 3/omega*4/(omega-1)


########################################################################
### domanda 3

ris = 1 - 0.6 - 0.7 + 0.4

########################################################################
### domanda 4

p = 1/9 # probabilità che sia dispari
ris = p + 2*p + p

########################################################################
### domanda 5

# 1) la probabilità che Giovanni vada in montagna questa domenica:
p1 <- 0.85*(1-0.1) + (1-0.7)*(0.1)

# 2) la probabilità che Giovanni sia in montagna e che piova
p2 <- (1-0.7)*0.1

# 3) all’uscita del cinema hai appena incontrato Giovanni, con che probabilità piove?
p3 <- 0.7*0.1/(1-p1)

########################################################################
### domanda 6

#
p1 = 1 - pbinom(0, 2, 1/4)

# 
p2 = 0.35*(0.5*0.5) + 0.65*(0.75*0.75)

# 
p3 = 0.35*0.5 + 0.65*3/4

#
p4 = p3

########################################################################
### domanda 6

tot = 100
pA = (15+4)/tot
pB = (15+80)/tot
pAB = 15/tot
pAoB = pA + pB - pAB
p4 = 80/100
pAdatoB = pAB/pB
