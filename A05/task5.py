class Student: 
    def __init__(self, lastName='Popescu', gpa=3.8):
        if isinstance(lastName, str):
            self.lastName = lastName
        else: 
            print("Warning, student's lastName is not a string. Defulting to 'Popescu'")
            
        if gpa >= 0 and gpa <= 4:
            self.gpa = gpa
        else:
            print("Warning, gpa is not between 0 and 4. Defaulting to gpa=3.8.")
            self.gpa = 3.8

    def compareGPA(self, other):
        if self.gpa < other.gpa:
            print(other.lastName)
        else:
            print(self.lastName)
