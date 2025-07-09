


class Drobi:
    chisl = 0
    znamen = 1
    def decF(self):
        return self.chisl/self.znamen
    def printF(self):
        if self.znamen == 1:
            return str(self.chisl)
        else:
            return str(self.chisl) + '/' + str(self.znamen)
    def checkDrob(self):
        if self.znamen < 0:
            self.znamen *= -1
            self.chisl *= -1
    def __init__(self, value1, value2):
            self.chisl = value1
            self.znamen = value2
    def OptimizeDrob(self):
        for n in range(self.znamen, 1, -1):
            if self.znamen % n == 0 and self.chisl % n == 0:
                self.znamen = self.znamen//n
                self.chisl = self.chisl//n
    def checkRes(self):
        if (self.znamen == 0):
            return "Division by zero"
        return self
    





def Add(a, b):
   result = Drobi(a.chisl * b.znamen + a.znamen * b.chisl, a.znamen * b.znamen)
   result.OptimizeDrob()
   return result

def Subtr(a,b):
    bTmp = Drobi(-1*b.chisl, b.znamen)
    result = Drobi(0,1)
    result = Add(a, bTmp)
    return result


def Multi(a,b):
    result = Drobi(a.chisl*b.chisl, a.znamen*b.znamen)
    result.OptimizeDrob()
    return result


def Divi(a,b):
    bTmp = Drobi(b.znamen, b.chisl)
    result = Drobi(0,1)
    bTmp.checkDrob()
    result = Multi(a, bTmp)
    return result
    


def makeNumberFromStr(str):
    res = 1
    i = 0
    if str[0] == '-':
        res = -1
        str = str[1:]
    
    while i < len(str) and str[i] >= '0' and str[i] <= '9':
        i+=1
    res = res * int(str[0:i])
    return res


def deleteTrashSymbs(str):
    i = 0
    count_of_minuses = 0
    while i < len(str) and (str[i] > '9' or str[i] < '0'):
        if (str[i] != '-' and str[i] != ' '):
            return "invalid syntax of formula"
        if str[i] == '-':
            count_of_minuses += 1
        i += 1
    res = str[i:]
    if (count_of_minuses % 2 == 1):
        res = '-' + res
    return res

def moveToFirstNNS(str):
    i = 0
    if len(str) == 0:
        return ''
    while '0' <= str[i] <= '9' or str[i] == ' ':
        i += 1
        if i == len(str):
            return ''
    return str[i:]

def NextNumTransfer(str):
    res = deleteTrashSymbs(str)
    i = 0
    while  res[i] >= '0' and res[i] <= '9':
        i += 1
        if i == len(res):
            return ''
    res = res[i:]
    res = deleteTrashSymbs(res)
    return res


def firstNonNumbericSymb(str):
    i = 0
    while str[i] <= '9' and str[i] >= '0' or str[i] == ' ':
        i+=1
        if i == len(str):
            return ' '
    return str[i]



def Calculator(formula):
    a = Drobi(0,1)
    b = Drobi(0,1)
    res = Drobi(0,1)
    temp = formula
    temp = deleteTrashSymbs(temp)
    if temp == "invalid syntax of formula":
        return "invalid syntax of formula"
    a.chisl = makeNumberFromStr(temp)
    temp = temp[1:]
    temp = moveToFirstNNS(temp)
    if len(temp) == 0:
        return a
    if temp[0] == '/':
        temp = temp[1:]
        a.znamen = makeNumberFromStr(temp)
        temp = temp[1:]
        temp = moveToFirstNNS(temp)
    if len(temp) != 0:
        operation = temp[0]
        temp = temp[1:]
        temp = deleteTrashSymbs(temp)
        if temp == "invalid syntax of formula":
            return "invalid syntax of formula"
        b.chisl = makeNumberFromStr(temp)
        temp = temp[1:]
        temp = moveToFirstNNS(temp)
        if len(temp) != 0:
            
            temp = temp[1:]
            b.znamen = makeNumberFromStr(temp)

    else:
        b.chisl = a.znamen
        a.znamen = 1
        operation = '/'
    
    
    if operation == '+':
       res = Add(a,b)
    elif operation == '-':
        res = Subtr(a,b)
    elif operation == '*':
       res = Multi(a,b)
    elif operation == '/':
        res = Divi(a,b)
    else:
        return "operation isn't correcte"
    res = res.checkRes()

    return res




res = Drobi(0,1)
formula = input("Input your primer \n")
res = Calculator(formula)
if res == "operation isn't correcte" or res == "invalid syntax of formula" or res == "Division by zero":
    print(res)
else:
    print(formula,'=',res.printF())
