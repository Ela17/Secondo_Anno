# descrittuva per dati categoriali

data("babies")
str(babies)

#creo una nuova variabile che vede smoke come dei factors
babies$smoke_f <- as.factor(babies$smoke)
levels(babies$smoke_f) <- c("mai", "sempre", "gravidanza", "molto tempo fa", "non registrato")

#calcolo le tabelle
table(babies$smoke_f)

# se volglio le frequenza relative divido table per la lunghezza di babies
table(babies$smoke_f)/nrow(babies)

#disegno
barplot(table(babies$smoke_f))
dotchart(table(babies$smoke_f))
pie(table(babies$smoke_f))
