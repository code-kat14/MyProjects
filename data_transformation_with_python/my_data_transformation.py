from datetime import datetime

csv_string = "Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At\nMale,Carl,Wilderman,carl,wilderman_carl@yahoo.com,29,Seattle,Safari iPhone,2,2020-03-06 16:37:56\nMale,Marvin,Lind,marvin,marvin_lind@hotmail.com,77,Detroit,Chrome Android,2,2020-03-02 13:55:51\nFemale,Shanelle,Marquardt,shanelle,marquardt.shanelle@hotmail.com,21,Las Vegas,Chrome,1,2020-03-05 17:53:05\nFemale,Lavonne,Romaguera,lavonne,romaguera.lavonne@yahoo.com,81,Seattle,Chrome,2,2020-03-04 10:33:53\nMale,Derick,McLaughlin,derick,mclaughlin.derick@hotmail.com,47,Chicago,Chrome Android,1,2020-03-05 15:19:48\n"

def transformed_time(element,time_index):
    time = element[time_index]
    time = datetime.strptime(time, '%Y-%m-%d %H:%M:%S')
    time = time.strftime('%H:%M:%S')
    if time > '06:00:00' and time < '11:59:00':
        return "morning"
    elif time > '12:00:00' and time < '17:59:00':
        return "afternoon"
    elif time > '18:00:00' and time < '23:59:00':
        return "evening"
    else:
        return "no valid time"

def transformed_age(element,age_index):
    age = int(element[age_index])
    if age <= 20:
        return "1->20"
    elif age <= 40:
        return "21->40"
    elif age <= 65:
        return "41->65"
    else:
        return "66->99"

def transformed_email(element,email_index):
    email = element[email_index].split('@')[1]     
    return email

def format_result_array(array):
    result = []
    for string in array:
        result.append(','.join(string))
    return result

def transformed_array(array):
    email_index = array[0].index('Email')
    age_index = array[0].index('Age')
    time_index = array[0].index('Order At')

    result_array = [array[0]]
    for row in array[1:]:
        email = transformed_email(row,email_index)
        age = transformed_age(row, age_index)
        time = transformed_time(row, time_index)
        for index, element in enumerate(row):
            if index == email_index:
                row[index] = email
            elif index == age_index:
                row[index] = age
            elif index == time_index:
                row[index] = time
        result_array.append(row)
    return format_result_array(result_array)

def my_data_transform(string):
    array = []
    row = string.split('\n')
    for data in range(len(row) - 1):
        array.append(row[data].split(','))
    return transformed_array(array)

my_data_transform(csv_string)
