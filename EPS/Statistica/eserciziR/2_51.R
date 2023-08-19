# prendi babyboom (UsingR) che contiene i dati sulle nascite di 44 bambini in un giorno a Brisbane.
# La variabile running.time registra il tempo di ogni nascita.
# Il comando diff(running.time) restituisce la differenza tra gli intervalli.
# Questi tempi spesso vengono modellati tramite una funzione esponenziale.
# Il coefficiente di variazione è vicino a 1?

# Ricordo che media=1/lambda e var=1/(lambda^2)
# cv = sd/mean

data("babyboom")
str(babyboom)

interarrival <- diff(babyboom$running.time)
hist(interarrival, breaks = 15)
sd(interarrival)/mean(interarrival)
