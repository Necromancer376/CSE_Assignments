
# 20BCE2110
# Malhar Dharmadhikari


df <- data.frame(read.csv("coursea_data.csv"))
df

#Q1
print("Malhar Dharmadhikari")
print("20BCE2110")
q1 <- data.frame(df$course_title, df$course_rating, df$course_students_enrolled)
View(q1)


# Q2
print("Malhar Dharmadhikari")
print("20BCE2110")

library(plyr)
q2df <- data.frame("orgs"=as.vector(df$course_organization), 
                   "rating"=as.vector(df$course_rating))
q2 <- aggregate(.~ orgs ,data =  q2df, FUN=mean)
temp <- count(q2df$orgs)
count <- temp$freq

xx <-barplot((q2$rating) ,names.arg = q2$orgs, las=2, 
             col=topo.colors(length(unique(count))), 
             ylim=c(4,5.5), xpd=FALSE, ylab="rating",
             main="20BCE2110 Malhar Dharmadhikari")
legend("topright", inset=0.0, title="No. of Courses", 
       as.character(unique(count)), fill=topo.colors(10), horiz=TRUE, cex=0.8)



#Q3
print("Malhar Dharmadhikari")
print("20BCE2110")
q3df <- data.frame(df$course_students_enrolled, df$course_rating)

cor(as.vector(as.integer(substr(df$course_students_enrolled,
                                1,
                                nchar(df$course_students_enrolled)-1))),
    as.vector(df$course_rating))

plot(q3df$df.course_rating, as.vector(as.integer(substr(df$course_students_enrolled,
                                                        1,
                                                        nchar(df$course_students_enrolled)-1))))
