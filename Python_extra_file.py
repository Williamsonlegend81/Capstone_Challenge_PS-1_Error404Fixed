lst1 = ["PC110(A)","AM",3,True,190,1]
lst2 = ["SC107(A)","MKG",3,True,190,1]
lst3 = ["IT112(A)","BG",3,True,190,1]
lst4 = ["EL111(A)","SM",3,True,190,1]
lst5 = ["IT113(A)","MK",3,True,190,1]
lst6 = ["IC101(A)","AKR",1,True,300,1]
lst7 = ["HM218(A)","SJ",3,True,190,3]
lst8 = ["CT204(A)","HP",3,True,190,3]
lst9 = ["IT216(A)","PB",3,True,190,3]
lst10 = ["IT227(A)","AKM",3,True,190,3]
lst11 = ["SC223(A)","AT",3,True,190,3]
Monday = []
Tuesday = []
Wednesday = []
Thursday = []
Friday = []

lstnest = [lst2,lst3,lst4,lst5,lst6]
for list in lstnest:
    if (list[2]>0 and list[3]!=False and len(Monday)<=3):
        Monday.append(list[0])
        list[3] = False
        list[2] = list[2]-1
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
for list in lstnest:
    if (list[2]>0 and list[3]!=False and len(Tuesday)<=3):
        Tuesday.append(list[0])
        list[3] = False
        list[2] = list[2]-1
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
for list in lstnest:
    if (list[2]>0 and list[3]!=False and len(Wednesday)<3):
        Wednesday.append(list[0])
        list[3] = False
        list[2] = list[2]-1
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
for list in lstnest:
    if (list[2]>0 and list[3]!=False and len(Thursday)<=2):
        Thursday.append(list[0])
        list[3] = False
        list[2] = list[2]-1
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
for list in lstnest:
    if (list[2]>0 and list[3]!=False and len(Friday)<=3):
        Friday.append(list[0])
        list[3] = False
        list[2] = list[2]-1
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
Tuesday.insert(0,"PC110(A)")
Wednesday.insert(0,"PC110(A)")
Friday.insert(0,"PC110(A)")
lstnest2 = [lst1,lst2,lst3,lst4,lst5,lst6,lst7,lst8,lst9,lst10,lst11]
lstnest3 = []
for list in lstnest2:
    if (list[5]==3):
        lstnest3.append(list)
# print(lstnest3)
# print(Monday)
# print(Tuesday)
# print(Wednesday)
# print(Thursday)
# print(Friday)
Monday_2 = []
Tuesday_2 = []
Wednesday_2 = []
Thursday_2 = []
Friday_2 = []
for element in Monday:
    Monday_2.append([element])
# print(Monday_2)
for element in Tuesday:
   Tuesday_2.append([element])
# print(Tuesday_2)
for element in Wednesday:
    Wednesday_2.append([element])
# print(Wednesday_2)
for element in Thursday:
    Thursday_2.append([element])
# print(Thursday_2)
for element in Friday:
    Friday_2.append([element])
# print(Friday_2)
lst_last = lstnest3.pop(0)
# print(lstnest3)
lec_Monday_3 = 0
for list in lstnest3:
    if (list[2]>0 and list[3]!=False and len(Monday_2)<5 and lec_Monday_3<2):
        Monday_2.append([list[0]])
        list[2] = list[2]-1
        list[3] = False
        lec_Monday_3 = lec_Monday_3+1
    elif (list[2]>0 and list[3]!=False and lec_Monday_3<2):
        for i in range(len(Monday_2)):
            if (len(Monday_2[i])<=3 and list[3]!=False):
                Monday_2[i].append(list[0])
                list[2] = list[2]-1
                lec_Monday_3 = lec_Monday_3+1
                list[3] = False
                if (lec_Monday_3>=2):
                    break
for list in lstnest3:
    if (list[2]>0):
        list[3] = True
# print(lstnest3)
# print(Tuesday_2)
lec_Tuesday_3 = 0
for list in lstnest3:
    if (list[2]>0 and list[3]!=False and len(Tuesday_2)<5 and lec_Tuesday_3<4):
        Tuesday_2.append([list[0]])
        list[2] = list[2]-1
        list[3] = False
        lec_Tuesday_3 = lec_Tuesday_3+1
    elif (list[2]>0 and list[3]!=False and lec_Tuesday_3<4):
        for i in range(len(Tuesday_2)):
            if (len(Tuesday_2[i])<2 and list[3]!=False):
                Tuesday_2[i].append(list[0])
                list[2] = list[2]-1
                lec_Tuesday_3 = lec_Tuesday_3+1
                list[3] = False
                if (lec_Tuesday_3>=4):
                    break
for list in lstnest3:
    if (list[2]>0):
        list[3] = True
# print(lstnest3)
lec_Wednesday_3 = 0
for list in lstnest3:
    if (list[2]>0 and list[3]!=False and len(Wednesday_2)<5 and lec_Wednesday_3<2):
        Wednesday_2.append([list[0]])
        list[2] = list[2]-1
        list[3] = False
        lec_Wednesday_3 = lec_Wednesday_3+1
    elif (list[2]>0 and list[3]!=False and lec_Wednesday_3<2):
        for i in range(len(Wednesday_2)):
            if (len(Wednesday_2[i])<2 and list[3]!=False):
                Wednesday_2[i].append(list[0])
                list[2] = list[2]-1
                lec_Wednesday_3 = lec_Wednesday_3+1
                list[3] = False
                if (lec_Wednesday_3>=2):
                    break
lec_Thursday_3 = 0
for list in lstnest3:
    if (list[2]>0):
        list[3] = True
for list in lstnest3:
    if (list[2]>0 and list[3]!=False and len(Thursday_2)<5 and lec_Thursday_3<2):
        Thursday_2.append([list[0]])
        list[2] = list[2]-1
        list[3] = False
        lec_Thursday_3 = lec_Thursday_3+1
    elif (list[2]>0 and list[3]!=False and lec_Thursday_3<2):
        for i in range(len(Thursday_2)):
            if (len(Thursday_2[i])<2 and list[3]!=False):
                Thursday_2[i].append(list[0])
                list[2] = list[2]-1
                lec_Thursday_3 = lec_Thursday_3+1
                list[3] = False
                if (lec_Thursday_3>=2):
                    break
lec_Friday_3 = 0
for list in lstnest3:
    if (list[2]>0):
        list[3] = True
for list in lstnest3:
    if (list[2]>0 and list[3]!=False and len(Friday_2)<5 and lec_Friday_3<2):
        Friday_2.append([list[0]])
        list[2] = list[2]-1
        list[3] = False
        lec_Friday_3 = lec_Friday_3+1
    elif (list[2]>0 and list[3]!=False and lec_Friday_3<2):
        for i in range(len(Thursday_2)):
            if (len(Friday_2[i])<2 and list[3]!=False):
                Friday_2[i].append(list[0])
                list[2] = list[2]-1
                lec_Friday_3 = lec_Friday_3+1
                list[3] = False
                if (lec_Friday_3>=2):
                    break
for list in Monday_2:
    if (len(list)<2 and lst_last[3]!=False):
        list.append(lst_last[0])
        lst_last[2] = lst_last[2]-1
        lst_last[3] = False
if (lst_last[2]>0):
    lst_last[3] = True
for list in Wednesday_2:
    if (len(list)<2 and lst_last[3]!=False):
        list.append(lst_last[0])
        lst_last[2] = lst_last[2]-1
        lst_last[3] = False
if (lst_last[2]>0):
    lst_last[3] = True
for list in Friday_2:
    if (len(list)<2 and lst_last[3]!=False):
        list.append(lst_last[0])
        lst_last[2] = lst_last[2]-1
        lst_last[3] = False
if (lst_last[2]>0):
    lst_last[3] = True
print(Monday_2)
print(Tuesday_2)
print(Wednesday_2)
print(Thursday_2)
print(Friday_2)
print(lstnest3)
print(lst_last)

lst_1 = ["PC110(B)","AM",3,True,190,1]
lst_2 = ["SC107(B)","SB2",3,True,190,1]
lst_3 = ["IT112(B)","MK",3,True,190,1]
lst_4 = ["EL111(B)","RLD",3,True,190,1]
lst_5 = ["IT113(B)","BG",3,True,190,1]
lst_6 = ["HM218(B)","SJ",3,True,190,3]
lst_7 = ["CT204(B)","PK",3,True,190,3]
lst_8 = ["IT216(B)","SP",3,True,190,3]
lst_9 = ["IT227(B)","SB",3,True,190,3]
lst_10 = ["SC223(B)","RM",3,True,190,3]
lst_nested_B = [lst_1,lst_2,lst_3,lst_4,lst_5,lst_6,lst_7,lst_8,lst_9,lst_10]
lst_sem_1_B = []
for list in lst_nested_B:
    if (list[5]==1):
        lst_sem_1_B.append(list)
print(lst_sem_1_B)
Days_of_Week = [Monday_2,Tuesday_2,Wednesday_2,Thursday_2,Friday_2]
for list in Days_of_Week:
    for i in range(4):
        if  ((list[i])[0]=="PC110(A)"):
           (list[i]).append("SC107(B)")
        elif  ((list[i])[0]=="SC107(A)"):
           (list[i]).append("EL111(B)")
        elif  ((list[i])[0]=="IT112(A)"):
           (list[i]).append("PC110(B)")
        elif  ((list[i])[0]=="EL111(A)"):
           (list[i]).append("SC107(B)")
        elif  ((list[i])[0]=="IT113(A)"):
           (list[i]).append("IT112(B)")
print(Monday_2)
print()
print(Tuesday_2)
print()
print(Wednesday_2)
print()
print(Thursday_2)
print()
print(Friday_2)
print()
counter = 0
for list in Days_of_Week:
    for i in range(4):
        if (len(list[i])<=2):
            counter = counter+1
print(counter)


# for list in lstnest3:
#     if (list[2]>0 and list[3]!=False and len(Monday_2)<5 and lec_Monday_3<=3):
#         Monday_2.append([list[0]])
#         list[2] = list[2]-1
#         lec_Monday_3 = lec_Monday_3+1
#     print(Monday_2)
    # elif (list[2]>0 and list[3]!=False and lec_Monday_3<=3):
    #     print(len(Monday_2))
    #     print(lec_Monday_3)
    #     if (len(Monday[0])<=3):
    #         Monday_2[0].append(list[0])
    #         lec_Monday_3 = lec_Monday_3+1
    #     elif (len(Monday[1])<=3):
    #         Monday_2[1].append(list[0])
    #         lec_Monday_3 = lec_Monday_3+1
    #     elif (len(Monday[2])<=3):
    #         Monday_2[2].append(list[0])
    #         lec_Monday_3 = lec_Monday_3+1
    #     elif (len(Monday[3])<=3):
    #         Monday_2[3].append(list[0])
    #         lec_Monday_3 = lec_Monday_3+1
    #     elif (len(Monday[4])<=3):
    #         Monday_2[4].append(list[0])
    #         lec_Monday_3 = lec_Monday_3+1