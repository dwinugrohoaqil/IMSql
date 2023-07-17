from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
import mysql.connector
from mysql.connector import Error
from kivy.clock import Clock
import time
from kivy.lang import Builder
from kivy.uix.screenmanager import ScreenManager, Screen
import mysql.connector
from kivy.animation import Animation
from kivy.core.window import Window
Window.clearcolor = (0.098,0.603,0.623,1)


class MainWindow(Screen):
    
    def val_in(self):
        global host, database, user, password
        host= self.ids.hst.text
        database= self.ids.db.text   
        user= self.ids.usr.text    
        password= self.ids.pwd.text 
        try:
            global connection
            connection = mysql.connector.connect(host= self.ids.hst.text,
                                                database= self.ids.db.text,
                                                user= self.ids.usr.text,
                                                password= self.ids.pwd.text)
            if connection.is_connected():
                db_Info = connection.get_server_info()
                print("Connected to MySQL Server version ", db_Info)
                cursor = connection.cursor()
                cursor.execute("select database();")
                record = cursor.fetchone()
                print("You're connected to database: ", record)
                self.manager.current="menu"

        except Error as e:
            print("Error while connecting to MySQL", e)
            
    def close_application():
        App.get_running_app().stop()
        Window.close()
            
class MenuWindow(Screen,BoxLayout):
    pass

class SecondWindow(Screen,BoxLayout):
    def stp_btn(self):
        dd.cancel()

    def readComm(self, _):
        global db, data
        namatblsensor = self.ids.tblnamesensor.text

        db = mysql.connector.connect(host=host, user=user, password=password, database=database)
        cursor = db.cursor()
        sql = "SELECT suara FROM " + namatblsensor + " ORDER BY datetime DESC LIMIT 1;"

        try:
            cursor.execute(sql)
            word = ''
            results = cursor.fetchall()
            for i in results:
                word = f'{word}\n{i}'
                self.ids.sh_id.text = f'{word}'
            db.commit()
        except:
            print("Error! Unable to fetch data")

    def ulang(self, arg):
        global db, data, hasil
        namatblsensor = self.ids.tblnamesensor.text

        db = mysql.connector.connect(host=host, user=user, password=password, database=database)
        cursor = db.cursor()
        sql = "SELECT * FROM " + namatblsensor + " ORDER BY datetime DESC LIMIT 1;"

        try:
            cursor.execute(sql)
            word = ''
            results = cursor.fetchall()
            for i in results:
                word = f'{word}\n{i}'
                self.ids.hasil.text = f'{word}'
            db.commit()
        except:
            print("Error! Unable to fetch data")

    def use_btn(self):
        global dd
        dd = Clock.schedule_interval(self.readComm, 1)
        dd = Clock.schedule_interval(self.ulang, 1)

    def stp_btn(self):
        dd.cancel()



           
class ThirdWindow(Screen):

    def stp_btn(self):
        dd.cancel()

    def readComm(self, _):
        global db, data
        namatblsensor = self.ids.tblnamesensor.text

        db = mysql.connector.connect(host=host, user=user, password=password, database=database)
        cursor = db.cursor()
        sql = "SELECT * FROM " + namatblsensor + " ORDER BY datetime DESC LIMIT 1;"

        try:
            cursor.execute(sql)
            word = ''
            results = cursor.fetchall()
            for i in results:
                word = f'{word}\n{i}'
                self.ids.sh_id.text = f'{word}'
            db.commit()
        except:
            print("Error! Unable to fetch data")

    def ulang(self, arg):
        global db, data, hasil
        namatblsensor = self.ids.tblnamesensor.text

        db = mysql.connector.connect(host=host, user=user, password=password, database=database)
        cursor = db.cursor()
        sql = "SELECT * FROM " + namatblsensor + " ORDER BY datetime DESC LIMIT 1;"

        try:
            cursor.execute(sql)
            word = ''
            results = cursor.fetchall()
            for i in results:
                word = f'{word}\n{i}'
                self.ids.hasil.text = f'{word}'
            db.commit()
        except:
            print("Error! Unable to fetch data")

    def use_btn(self):
        global dd
        dd = Clock.schedule_interval(self.readComm, 1)
        dd = Clock.schedule_interval(self.ulang, 1)

    def stp_btn(self):
        dd.cancel()


class FourWindow(Screen):
    def stp_btn(self):
        dd.cancel()

    def readComm(self,_):
        global db,data
        namatblsensor= self.ids.adcsensor.text
        
        db = mysql.connector.connect(host=host, user=user, password=password, database=database)
        cursor=db.cursor()
        sql = "SELECT * FROM " +namatblsensor+" ORDER BY datetime DESC LIMIT 1;"

        try:
            cursor.execute(sql)
            word=''
            # Fetch all the rows in a list of lists.
            results = cursor.fetchall()
            for i in results:
                word = f'{word}\n{i}' #n{i[0]} to select the first column
                self.ids.sh_id.text= f'{word}'
            #print (results)
            db.commit()               
            #print(results)
        except:
            print ("Error! Unable to fetch data" )  
        
        return
    def ulang(self,arg):
        global db,data,hasil
        namatblsensor= self.ids.tblnamesensor.text

        db = mysql.connector.connect(host=host, user=user, password=password, database=database)
        cursor=db.cursor()
        sql = "SELECT * FROM " +namatblsensor+" ORDER BY datetime DESC LIMIT 1;"

        try:
            cursor.execute(sql)
            word=''
            # Fetch all the rows in a list of lists.
            results = cursor.fetchall()
            for i in results:
                word = f'{word}\n{i}' #n{i[0]} to select the first column
                self.ids.hasil.text= f'{word}'
                
            #print (results)
            db.commit()               
            #print(results)
        except:
            print ("Error! Unable to fetch data" )  
        
        return       
    def use_btn(self):
        global dd
        dd = Clock.schedule_interval(self.readComm, 1)
        dd = Clock.schedule_interval(self.ulang, 1)

class WindowManager(ScreenManager):
    pass

kv = Builder.load_file("mine_infrared.kv")
    
class MyMainApp(App):
    title = "IMSql"
    def build(self):
        return kv
    
if __name__ == '__main__':
    MyMainApp().run()