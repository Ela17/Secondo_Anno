# bivariata: wt e smoke

data(babies)
babies$smoke_f <- as.factor(babies$smoke)
levels(babies$smoke_f) <- c("mai","sempre",
                            "pregravidanza",
                            "molto tempo fa",
                            "non registrato")

# 1: mettiamo a posto 999 = NA
# 2: trasformo in grammi

babies$wt[babies$wt == 999] <- NA
babies$wt_grammi <- babies$wt * 28.3495

# disegno i box plot affiancati per confrontarli
boxplot(babies$wt_grammi ~ babies$smoke_f)


#######################################
# bivariata: quant/quant
# correlazione campionaria e covarianza campionaria

data("fat")

#scatterplot di polso e collo
cor(fat$neck, fat$wrist)
plot(fat$neck, fat$wrist)

#scatterplot di polso e altezza
#inches -> cm
fat$height_cm <- fat$height * 2.54
cor(fat$height_cm, fat$wrist)
plot(fat$height_cm, fat$wrist)

#######################################
# correlazione di spearman

data("Animals")

plot(Animals$body, Animals$brain)

cor(Animals$body, Animals$brain) #pearson
# il valore dice che non sono linearmente correlate
# ma il grafico dice che una relazione c'è

# calcolo la correlazione con il metodo Spearman
cor(Animals$body, Animals$brain, method = "spearman")
# quindi c'è relazione di tipo monotono


########################################
# bivariata qualitativa/qualitativa

data("grades")

table(grades)

mosaicplot(table(grades))

grades_num <- list()
grades_num$prev <- as.numeric(grades$prev)
grades_num$grade <- as.numeric(grades$grade)

cor(grades_num$prev, grades_num$grade, method = "kendall")
