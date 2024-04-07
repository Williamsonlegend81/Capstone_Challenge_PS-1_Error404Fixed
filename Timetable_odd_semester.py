lst1 = ["PC110(A)","AM",3,True,190,"1"]
lst2 = ["SC107(A)","MKG",3,True,190,"1"]
lst3 = ["IT112(A)","BG",3,True,190,"1"]
lst4 = ["EL111(A)","SM",3,True,190,"1"]
lst5 = ["IT113(A)","MK",3,True,190,"1"]
lst6 = ["IC101(A)","AKR",1,True,300,"1"]
lst7 = ["HM218(A)","SJ",3,True,190,"3"]
lst8 = ["CT204(A)","HP",3,True,190,"3"]
lst9 = ["IT216(A)","PB",3,True,190,"3"]
lst10 = ["IT227(A)","AKM",3,True,190,"3"]
lst11 = ["SC223(A)","AT",3,True,190,"3"]
Monday = []
Tuesday = []
Wednesday = []
Thursday = []
Friday = []

lstnest = [lst2,lst3,lst4,lst5,lst6]
for lister in lstnest:
    if (lister[2]>0 and lister[3]!=False and len(Monday)<=3):
        Monday.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        lister[3] = False
        lister[2] = lister[2]-1
        if (len(Monday)>=4):
            break
if (lst2[2]>0):
    lst2[3] = True
if (lst3[2]>0):
    lst3[3] = True
if (lst4[2]>0):
    lst4[3] = True
if (lst5[2]>0):
    lst5[3] = True
if (lst6[2]>0):
    lst6[3] = True
for lister in lstnest:
    if (lister[2]>0 and lister[3]!=False and len(Tuesday)<=3):
        Tuesday.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        lister[3] = False
        lister[2] = lister[2]-1
        if (len(Tuesday)>=4):
            break
if (lst2[2]>0):
    lst2[3] = True
if (lst3[2]>0):
    lst3[3] = True
if (lst4[2]>0):
    lst4[3] = True
if (lst5[2]>0):
    lst5[3] = True
if (lst6[2]>0):
    lst6[3] = True
for lister in lstnest:
    if (lister[2]>0 and lister[3]!=False and len(Wednesday)<3):
        Wednesday.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        lister[3] = False
        lister[2] = lister[2]-1
        if (len(Wednesday)>=3):
            break
if (lst2[2]>0):
    lst2[3] = True
if (lst3[2]>0):
    lst3[3] = True
if (lst4[2]>0):
    lst4[3] = True
if (lst5[2]>0):
    lst5[3] = True
if (lst6[2]>0):
    lst6[3] = True
for lister in lstnest:
    if (lister[2]>0 and lister[3]!=False and len(Thursday)<=2):
        Thursday.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        lister[3] = False
        lister[2] = lister[2]-1
        if (len(Thursday)>=3):
            break
if (lst2[2]>0):
    lst2[3] = True
if (lst3[2]>0):
    lst3[3] = True
if (lst4[2]>0):
    lst4[3] = True
if (lst5[2]>0):
    lst5[3] = True
if (lst6[2]>0):
    lst6[3] = True
for lister in lstnest:
    if (lister[2]>0 and lister[3]!=False and len(Friday)<=3):
        Friday.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        lister[3] = False
        lister[2] = lister[2]-1
        if (len(Friday)>=3):
            break
if (lst2[2]>0):
    lst2[3] = True
if (lst3[2]>0):
    lst3[3] = True
if (lst4[2]>0):
    lst4[3] = True
if (lst5[2]>0):
    lst5[3] = True
if (lst6[2]>0):
    lst6[3] = True
if (len(Friday)<2):
    s = Monday.pop(len(Monday)-2)
    Friday.append(s)
Joday = Tuesday
Tuesday = Thursday
Thursday = Joday
Tuesday.insert(0,"PC110(A) AM 280 1")
Wednesday.insert(0,"PC110(A) AM 280 1")
Friday.insert(0,"PC110(A) AM 280 1")
lstnest2 = [lst1,lst2,lst3,lst4,lst5,lst6,lst7,lst8,lst9,lst10,lst11]
lstnest3 = []
for lister in lstnest2:
    if (lister[5]=="3"):
        lstnest3.append(lister)
print(lstnest3)
print(Monday)
print(Tuesday)
print(Wednesday)
print(Thursday)
print(Friday)