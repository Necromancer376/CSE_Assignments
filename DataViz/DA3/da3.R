
# Malhar Dharmadhikari
#20BCE2110


# Q1
print("Malhar Dharmadhikari")
print("20BCE2110")

my_data <- read.csv("fortune1000.csv")
head(my_data)


#Q2
print("Malhar Dharmadhikari")
print("20BCE2110")

table(my_data$Sector)


# Q3
print("Malhar Dharmadhikari")
print("20BCE2110")

temp_data <- my_data[order(my_data$Revenue), ]
unique(temp_data$Industry)[1:10]


# Malhar Dharmadhikari
#20BCE2110
# Q4
temp_data <- my_data[order(-my_data$Revenue),]

rev20 = as.array(temp_data$Revenue[1:20])
comp20 = as.array(temp_data$Company[1:20])

barplot(rev20, names.arg = comp20, ylim=c(0,500000), las=2, cex.names = 1,
        main="Malhar Dharmadhikari 20BCE2110")


# Malhar Dharmadhikari
#20BCE2110
# Q5

q5_data <- my_data[order(-my_data$Employees),]

size = as.array(q5_data$Employees[1:20])/150000
plot(q5_data$Profits[1:20] ~ q5_data$Revenue[1:20], col="black", ylab="profits", xlab="revenue",
     pch=1, cex=size, lwd=4, main="Malhar Dharmadhikari 20BCE2110")

