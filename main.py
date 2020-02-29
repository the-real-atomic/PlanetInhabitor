#!/bin/python3

# COPYFRIGHT 2008-2002 BeastMaster34.5

class Person:
    happiness = 0
    name = 'beastmaster34.5'

    def __init__(self, happiness):
        self.happiness = happiness

class World:
    population = 0
    people = []

    def __init__(self, pop):
        self.population = pop
        for i in range(0, pop):
            # Make the classes
            self.people.append(Person(i))

if __name__ == '__main__':
    world = World(7800000000)
    print('Good job!')
