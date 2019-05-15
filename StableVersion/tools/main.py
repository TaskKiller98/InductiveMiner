from tkinter import *
from graphviz import Source
import subprocess
import tkinter.ttk as ttk
from tkinter import filedialog


class MainWindow:

    def __init__(self, main):
        self.main = main
        self.set_style()
        self.set_csv(main)



    def set_style(self):
        s = ttk.Style()
        s.configure('blue.TButton', foreground='black', background='#E01061', font=("Verdana", 24, 'bold'))
        s.configure('red.TLabel', font=("Verdana", 24, 'bold'))
        s.configure('pink.TMenubutton',  background="#f442c8", font=("Verdana", 24, 'bold'))



    def set_csv(self, main):
        # self.entery1 = ttk.Entry(main, font=("Verdana", 24, 'bold'), style="red.TButton")
        self.button2 = ttk.Button(main, text="Выбрать файл", style="blue.TButton")
        # self.label1 = ttk.Label(main, style="red.TLabel")
        self.label3 = ttk.Label(main, style="red.TLabel")
        options = ["Граф в формате", "pdf", "svg"]
        self.value = StringVar()
        self.option_menu = ttk.OptionMenu(main, self.value, *options, style="pink.TMenubutton")



        # self.entery1.place(x=10, y=100)
        self.button2.place(y=200, relx=0.5, anchor=CENTER)
        # self.label1.place(x=150, y=700)
        self.option_menu.place(y=300, relx=0.5, anchor=CENTER)
        self.label3.place(y=100, relx=0.5, anchor=CENTER)

        self.label3["text"] = "Загрузите исходный лог"
        self.button2.bind("<Button-1>", self.openfile)


    def openfile(self, event):
        filename = filedialog.askopenfile(mode='r', filetypes=(("Table files", "*.ind"),("All files", "*.*")))
        tmp = subprocess.call(["./src", filename.name])
        print(tmp)
        path = "../res/Petri_net.dot"
        try:
            s = Source.from_file(path)
            s.format = self.value.get()
            s.view()
        except BaseException:
            print("Exception!")



root = Tk()

root.title("Inductive Miner")
root.geometry("700x500")
root.resizable(0, 0)

q = MainWindow(root)

root.configure(background="#10E0C5")
root.mainloop()
