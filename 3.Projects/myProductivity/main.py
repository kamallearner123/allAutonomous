# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

from iseeyou import *
import time
import os

def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_hi('welcome to I see you App')

    #1) Create a file to log.
    file_name = get_file_name()
    with open(file_name, "w") as fd:
        cam = cv2.VideoCapture(0)
        while True:
            img_name = get_file_name()
            print("Calling API to check the person !!!")
            fd.write(str(get_quote_of_person(cam, os.getcwd()+"/images/"+img_name)))
            time.sleep(120)


# See PyCharm help at https://www.jetbrains.com/help/pycharm/
