import math 

# Calculate the total amount of interestr gained on an initial investment with either
# simple or compound interest.
def calc_investment():
    print("\nInvestment Calculator")
    print("---------------------")
    try:
        init_amount = float(input("\nHow much money are you depositing: £"))
        interest = float(input("Enter the interest rate as a %: "))
        years = int(input("Enter the total length of investment (in years): "))
    except:
        print("Invlid Input detected! Exiting program.")
        return 
    
    validInp = False 
    while not validInp:
        type = input("\nDo you want 'simple' or 'compound' interest? ")
        if type.lower() == "simple" or type.lower() == "compound":
            validInp = True
        else:
            print("Invalid input! Please type either 'simple' or 'compound'.") 
    
    # Calculate results
    if type.lower() == "simple":
        final_amount = init_amount * (1 + (interest/100) * years)
    else:
        final_amount = init_amount * math.pow((1 + (interest/100)), years) 
    
    # Print results
    print("\nWith an initial investment of £{0:.2f} over {1:d} years, you will have earned £{2:.2f} in interest".format(init_amount, years, (final_amount-init_amount)))
    return 

# Calculate the total monthly repayments on a house 
def calc_bond():
    print("\nBond Calculator")
    print("---------------")
    try:
        cur_value = float(input("\nEnter the present value: £"))
        interest = float(input("Enter the % annual interest: "))
        interest = (interest / 100) / 12
        months = int(input("Enter the number of months you wish to make payments for: "))
    except:
        print("Invlid Input detected! Exiting program.")
        return 

    # Calculate and print result
    repayment = (interest * cur_value) / (1 - (1 + interest)**(-months))
    print("\nYour monthly repayments will be: £{0:.2f}".format(repayment))
    return




# Get the user to pick the type of investment they wish to calculate
print("WELCOME")
print("-------")
print("\nPlease select an investment type:")
print(  "---------------------------------")
print("1. INVESTEMENT - to calculate the amount of interest you'll earn on your investment")
print("2. BOND        - to calculate the amount you'll have to pay on a home loan")
# print("3. EXIT")
opt = int(input("Enter the integer option "))

if opt == 1:
    calc_investment()
elif opt == 2:
    calc_bond()
else:
    print("Invalid Input!")