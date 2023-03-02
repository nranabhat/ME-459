class ComplexNumber:
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag

    def __abs__(self):
        return (self.real ** 2 + self.imag ** 2) ** 0.5

    def __format__(self, format_spec):
        return '{}{}j'.format(format(self.real, format_spec), 
                              format(self.imag, format_spec))
    

    