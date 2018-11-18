#!/usr/bin/env python3

class Dog():
    """dog class"""

    def __init__(self, name, age):
        """ init instancem auto return an instance """
        self.name = name;
        self.age = age;

    def sit(self):
        """ sit down """
        print(self.name.title(), "is sitting now")

    def roll_over(self):
        """ roll over """
        print(self.name.title(), "is rolling over")

class Car():
    """ car instance """
    def __init__(self, make, model, year):
        self.make = make
        self.model = model
        self.year = year
        self.odometer = 0
        self.gas = 0

    def get_descript_name(self):
        print("this car has ", str(self.odometer) + " miles on it.")

    def fill_gas_bank(self):
        self.gas = 100

class Battery():
    def __init__(self, battery_size = 70):
        self.battery_size = battery_size

class ElectricCar(Car):
    def __init__(self, make, model, year):
        super().__init__(make, model, year)
        self.battery = Battery()

    def descript_battery(self):
        """ new function for derived class """
        print('this car has', str(self.battery.battery_size), '-kWh battery')

    def fill_gas_bank(self):
        """ over-write function """
        print('no need to fill gas')

m_dog = Dog("willia", 6)
m_dog.sit()
m_dog.roll_over()

m_electricCar = ElectricCar('tesla', 'nodel s', 2017)
m_electricCar.get_descript_name()
m_electricCar.descript_battery()
m_electricCar.fill_gas_bank()