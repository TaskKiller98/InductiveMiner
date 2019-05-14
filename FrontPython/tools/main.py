from graphviz import Source
import subprocess



tmp=subprocess.call("./src")
print(tmp)
path = "../res/Petri_net.dot"
try:
     s = Source.from_file(path)
     s.format = "pdf"
     s.view()
except:
     print("Toha-loh")

