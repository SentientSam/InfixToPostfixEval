##############################################
# Author: Samuel Lamb												 #
# Class: cop4530                             #
# Assignment: Assignemnt 3                   # 
# Filename: makefile                         #
# Date Created: 2/13/2020                    #
# Description: makefile for assignment 2     #
##############################################

CC= g++ -g -std=c++11 -Wall -Wextra -I. -o

main: proj3.x # Paren.x test.x


# test.x: test.cpp stack.h stack.hpp
# 			$(CC) test.x test.cpp

proj3.x: in2post.cpp stack.h stack.hpp
			$(CC) proj3.x in2post.cpp

# Paren.x: TestParenChecker.cpp stack.h stack.hpp
# 			$(CC) Paren.x TestParenChecker.cpp

clean: 
		-rm *.o
		-rm *.h.gch
		-rm *.x






































































