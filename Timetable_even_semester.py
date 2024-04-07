lst1 = ["HM106(A)","BK",3,True,190,"2"]
lst2 = ["IC121(A)","SR",3,True,190,"2"]
lst3 = ["IT205(A)","SDG",3,True,190,"2"]
lst4 = ["SC205(A)","AT2",3,True,190,"2"]
lst5 = ["SC217(A)","GD",3,True,190,"2"]
lst6 = ["IT206(A)","PhD",1,True,300,"2"]
lst7 = ["HM116(A)","Gaurav",3,True,190,"4"]
lst8 = ["EL203(A)","BM",3,True,190,"4"]
lst9 = ["IT214(A)","PMJ",3,True,190,"4"]
lst10 = ["CT216(A)","YV",3,True,190,"4"]
lst11 = ["SC224(A)","MS",3,True,190,"4"]
Monday = []
Tuesday = []
Wednesday = []
Thursday = []
Friday = []

lst_nest_2 = [lst2,lst3,lst4,lst5,lst6]
for lister in lst_nest_2:
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
for lister in lst_nest_2:
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
for lister in lst_nest_2:
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
for lister in lst_nest_2:
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
for lister in lst_nest_2:
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
Tuesday.insert(0,"HM106(A) BK 190 2")
Wednesday.insert(0,"HM106(A) BK 190 2")
Friday.insert(0,"HM106(A) BK 190 2")
lstnest2 = [lst1,lst2,lst3,lst4,lst5,lst6,lst7,lst8,lst9,lst10,lst11]
lst_nest_4 = []
for lister in lstnest2:
    if (lister[5]=="4"):
        lst_nest_4.append(lister)
Monday_2 = []
Tuesday_2 = []
Wednesday_2 = []
Thursday_2 = []
Friday_2 = []
for element in Monday:
    Monday_2.append([element])
for element in Tuesday:
   Tuesday_2.append([element])
for element in Wednesday:
    Wednesday_2.append([element])
for element in Thursday:
    Thursday_2.append([element])
for element in Friday:
    Friday_2.append([element])
lst_last = lst_nest_4.pop(0)
lec_Monday_3 = 0
for lister in lst_nest_4:
    if (lister[2]>0 and lister[3]!=False and len(Monday_2)<5 and lec_Monday_3<2):
        Monday_2.append([lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]])
        lister[2] = lister[2]-1
        lister[3] = False
        lec_Monday_3 = lec_Monday_3+1
    elif (lister[2]>0 and lister[3]!=False and lec_Monday_3<2):
        for i in range(len(Monday_2)):
            if (len(Monday_2[i])<=3 and lister[3]!=False):
                Monday_2[i].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lec_Monday_3 = lec_Monday_3+1
                lister[3] = False
                if (lec_Monday_3>=2):
                    break
for lister in lst_nest_4:
    if (lister[2]>0):
        lister[3] = True
lec_Tuesday_3 = 0
for lister in lst_nest_4:
    if (lister[2]>0 and lister[3]!=False and len(Tuesday_2)<5 and lec_Tuesday_3<4):
        Tuesday_2.append([lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]])
        lister[2] = lister[2]-1
        lister[3] = False
        lec_Tuesday_3 = lec_Tuesday_3+1
    elif (lister[2]>0 and lister[3]!=False and lec_Tuesday_3<4):
        for i in range(len(Tuesday_2)):
            if (len(Tuesday_2[i])<2 and lister[3]!=False):
                Tuesday_2[i].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lec_Tuesday_3 = lec_Tuesday_3+1
                lister[3] = False
                if (lec_Tuesday_3>=4):
                    break
for lister in lst_nest_4:
    if (lister[2]>0):
        lister[3] = True
lec_Wednesday_3 = 0
for lister in lst_nest_4:
    if (lister[2]>0 and lister[3]!=False and len(Wednesday_2)<5 and lec_Wednesday_3<2):
        Wednesday_2.append([lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]])
        lister[2] = lister[2]-1
        lister[3] = False
        lec_Wednesday_3 = lec_Wednesday_3+1
    elif (lister[2]>0 and lister[3]!=False and lec_Wednesday_3<2):
        for i in range(len(Wednesday_2)):
            if (len(Wednesday_2[i])<2 and lister[3]!=False):
                Wednesday_2[i].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lec_Wednesday_3 = lec_Wednesday_3+1
                lister[3] = False
                if (lec_Wednesday_3>=2):
                    break
lec_Thursday_3 = 0
for lister in lst_nest_4:
    if (lister[2]>0):
        lister[3] = True
for lister in lst_nest_4:
    if (lister[2]>0 and lister[3]!=False and len(Thursday_2)<5 and lec_Thursday_3<2):
        Thursday_2.append([lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]])
        lister[2] = lister[2]-1
        lister[3] = False
        lec_Thursday_3 = lec_Thursday_3+1
    elif (lister[2]>0 and lister[3]!=False and lec_Thursday_3<2):
        for i in range(len(Thursday_2)):
            if (len(Thursday_2[i])<2 and lister[3]!=False):
                Thursday_2[i].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lec_Thursday_3 = lec_Thursday_3+1
                lister[3] = False
                if (lec_Thursday_3>=2):
                    break
lec_Friday_3 = 0
for lister in lst_nest_4:
    if (lister[2]>0):
        lister[3] = True
for lister in lst_nest_4:
    if (lister[2]>0 and lister[3]!=False and len(Friday_2)<5 and lec_Friday_3<2):
        Friday_2.append([lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]])
        lister[2] = lister[2]-1
        lister[3] = False
        lec_Friday_3 = lec_Friday_3+1
    elif (lister[2]>0 and lister[3]!=False and lec_Friday_3<2):
        for i in range(len(Thursday_2)):
            if (len(Friday_2[i])<2 and lister[3]!=False):
                Friday_2[i].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lec_Friday_3 = lec_Friday_3+1
                lister[3] = False
                if (lec_Friday_3>=2):
                    break
for lister in Monday_2:
    if (len(lister)<2 and lst_last[3]!=False):
        lister.append(lst_last[0]+" "+lst_last[1]+" "+str(lst_last[4])+" "+lst_last[5])
        lst_last[2] = lst_last[2]-1
        lst_last[3] = False
if (lst_last[2]>0):
    lst_last[3] = True
for lister in Wednesday_2:
    if (len(lister)<2 and lst_last[3]!=False):
        lister.append(lst_last[0]+" "+lst_last[1]+" "+str(lst_last[4])+" "+lst_last[5])
        lst_last[2] = lst_last[2]-1
        lst_last[3] = False
if (lst_last[2]>0):
    lst_last[3] = True
for lister in Friday_2:
    if (len(lister)<2 and lst_last[3]!=False):
        lister.append(lst_last[0]+" "+lst_last[1]+" "+str(lst_last[4])+" "+lst_last[5])
        lst_last[2] = lst_last[2]-1
        lst_last[3] = False
if (lst_last[2]>0):
    lst_last[3] = True

lst_1 = ["HM106(B)","BK",3,True,280,"2"]
lst_2 = ["IC121(B)","PK",3,True,190,"2"]
lst_3 = ["IT205(B)","MK",3,True,190,"2"]
lst_4 = ["SC205(B)","RLD",3,True,190,"2"]
lst_5 = ["SC217(B)","BG",3,True,190,"2"]
lst_6 = ["HM116(B)","Cyril",3,True,280,"4"]
lst_7 = ["EL203(B)","YA",3,True,190,"4"]
lst_8 = ["IT214(B)","PMJ",3,True,190,"4"]
lst_9 = ["CT216(B)","YV",3,True,190,"4"]
lst_10 = ["SC224(B)","MK2",3,True,190,"4"]
lst_nested_B = [lst_1,lst_2,lst_3,lst_4,lst_5,lst_6,lst_7,lst_8,lst_9,lst_10]
lst_sem_1_B = []
for lister in lst_nested_B:
    if (lister[5]==1):
        lst_sem_1_B.append(lister)
Days_of_Week = [Monday_2,Tuesday_2,Wednesday_2,Thursday_2,Friday_2]
for lister in Days_of_Week:
    for i in range(4):
        if  ((lister[i])[0]=="HM106(A) BK 190 2"):
           (lister[i]).append("IT205(B) AR2 190 2")
        elif  ((lister[i])[0]=="SC205(A) AT2 190 2"):  
           (lister[i]).append("IC121(B) PK 190 2")
        elif  ((lister[i])[0]=="IT205(A) SDG 190 2"):
           (lister[i]).append("HM106(B) BK 280 2")
        elif  ((lister[i])[0]=="IC121(A) SR 190 2"):
           (lister[i]).append("SC217(B) GD 190 2")
        elif  ((lister[i])[0]=="SC217(A) GD 190 2"):
           (lister[i]).append("SC205(B) MKR 190 2")
for lister in Days_of_Week:
    for i in range(len(lister)):
        if "HM116(A) Gaurav 190 4" in lister[i]:
           (lister[i]).append("IT214(B) PMJ 190 4")
        elif "SC224(A) MS 190 4" in lister[i]:
           (lister[i]).append("CT216(B) YV 190 4")
        elif "IT214(A) PMJ 190 4" in lister[i]:
           (lister[i]).append("HM116(B) Cyril 280 4")
        elif "CT216(A) YV 190 4" in lister[i]:
           (lister[i]).append("SC224(B) MK2 190 4")
        elif "EL203(A) BM 190 4" in lister[i]:
           (lister[i]).append("EL203(B) YA 190 4")
lst_6_1 = ["SC407(A)","YV",3,True,300,"6"]
lst_nest_6 = [lst_6_1]
mon_0 = 0
mon_1 = 0
mon_2 = 0
mon_3 = 0
mon_4 = 0
tues_0 = 0
tues_1 = 0
tues_2 = 0
tues_3 = 0
tues_4 = 0
wed_0 = 0
wed_1 = 0
wed_2 = 0
wed_3 = 0
wed_4 = 0
thurs_0 = 0
thurs_1 = 0
thurs_2 = 0
thurs_3 = 0
thurs_4 = 0
fri_0 = 0
fri_1 = 0
fri_2 = 0
fri_3 = 0
fri_4 = 0
for lister in lst_nest_6:
    if (lister[2]>0 and lister[3]!=False):
        if (len(Monday_2[0])<=2 and mon_0==0):
            Monday_2[0].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            mon_0 = mon_0+1
        elif (len(Monday_2[1])<=2 and mon_1==0):
            Monday_2[1].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            mon_1 = mon_1+1
        elif (len(Monday_2[2])<=2 and mon_2==0):
            Monday_2[2].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            mon_2 = mon_2+1
        elif (len(Monday_2[3])<=2 and mon_3==0):
            Monday_2[3].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            mon_3 = mon_3+1
        elif (len(Monday_2[4])<=2 and mon_4==0):
            Monday_2[4].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            mon_4 = mon_4+1
for lister in lst_nest_6:
    if (lister[2]>0):
        lister[3] = True
for lister in lst_nest_6:
    if (lister[2]>0 and lister[3]!=False):
        if (len(Tuesday_2[0])<=2 and tues_0==0):
            Tuesday_2[0].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            tues_0 = tues_0+1
        elif (len(Tuesday_2[1])<=2 and tues_1==0):
            Tuesday_2[1].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            tues_1 = tues_1+1
        elif (len(Tuesday_2[2])<=2 and tues_2==0):
            Tuesday_2[2].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            tues_2 = tues_2+1
        elif (len(Tuesday_2[3])<=2 and tues_3==0):
            Tuesday_2[3].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            tues_3 = tues_3+1
        elif (len(Tuesday_2[4])<=2 and tues_4==0):
            Tuesday_2[4].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            tues_4 = tues_4+1
for lister in lst_nest_6:
    if (lister[2]>0):
        lister[3] = True
for lister in lst_nest_6:
    if (lister[2]>0 and lister[3]!=False):
        if (len(Wednesday_2[0])<=2 and wed_0==0):
            Wednesday_2[0].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            wed_0 = wed_0+1
        elif (len(Wednesday_2[1])<=2 and wed_1==0):
            Wednesday_2[1].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            wed_1 = wed_1+1
        elif (len(Wednesday_2[2])<=2 and wed_2==0):
            Wednesday_2[2].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            wed_2 = wed_2+1
        elif (len(Wednesday_2[3])<=2 and wed_3==0):
            Wednesday_2[3].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            wed_3 = wed_3+1
        elif (len(Wednesday_2[4])<=2 and wed_4==0):
            Wednesday_2[4].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            wed_4 = wed_4+1
for lister in lst_nest_6:
    if (lister[2]>0):
        lister[3] = True
for lister in lst_nest_6:
    if (lister[2]>0 and lister[3]!=False):
        if (len(Thursday_2[0])<=2 and thurs_0==0):
            Thursday_2[0].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            thurs_0 = thurs_0+1
        elif (len(Thursday_2[1])<=2 and thurs_1==0):
            Thursday_2[1].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            thurs_1 = thurs_1+1
        elif (len(Thursday_2[2])<=2 and thurs_2==0):
            Thursday_2[2].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            thurs_2 = thurs_2+1
        elif (len(Thursday_2[3])<=2 and thurs_3==0):
            Thursday_2[3].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            thurs_3 = thurs_3+1
        elif (len(Thursday_2[4])<=2 and thurs_4==0):
            Thursday_2[4].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            thurs_4 = thurs_4+1
for lister in lst_nest_6:
    if (lister[2]>0):
        lister[3] = True
for lister in lst_nest_6:
    if (lister[2]>0 and lister[3]!=False):
        if (len(Friday_2[0])<=2 and fri_0==0):
            Friday_2[0].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            fri_0 = fri_0+1
        elif (len(Friday_2[1])<=2 and fri_1==0):
            Friday_2[1].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            fri_1 = fri_1+1
        elif (len(Friday_2[2])<=2 and fri_2==0):
            Friday_2[2].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            fri_2 = fri_2+1
        elif (len(Friday_2[3])<=2 and fri_3==0):
            Friday_2[3].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            fri_3 = fri_3+1
        elif (len(Friday_2[4])<=2 and fri_4==0):
            Friday_2[4].append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            fri_4 = fri_4+1
for lister in lst_nest_6:
    if (lister[2]>0):
        lister[3] = True
lst_MnC_1 = ["MC215","SB2",3,True,65,"2"]
lst_MnC_2 = ["MC125","MS",3,True,65,"2"]
lst_MnC_3 = ["MC124","RM2",3,True,65,"2"]
lst_MnC_4 = ["MC122","TBD",2,True,65,"2"]
lst_MnC_4_1 = ["MC221","GP",3,True,65,"4"]
lst_MnC_4_2 = ["MC222","NKS",3,True,65,"4"]
lst_MnC_4_3 = ["MC223","PB",3,True,65,"4"]
lst_MnC_4_4 = ["MC224","VS",3,True,65,"4"]
lst_MnC_4_5 = ["MC225","SK",3,True,65,"4"]
lst_MnC_4_6 = ["MC226","RG",3,True,65,"4"]
lst_MnC_6_1 = ["MC321","PA",3,True,65,"6"]
lst_EvD_1 = ["ED121","PK2",3,True,25,"2"]
lst_nest_MnC_1 = [lst_MnC_1,lst_MnC_2,lst_MnC_3,lst_MnC_4]
lst_nest_MnC_4 = [lst_MnC_4_1,lst_MnC_4_2,lst_MnC_4_3,lst_MnC_4_4,lst_MnC_4_5,lst_MnC_4_6]
lst_nest_MnC_6 = [lst_MnC_6_1]
lst_nest_EvD = [lst_EvD_1]
lec_Monday_MnC = 0
lec_Tuesday_MnC = 0
lec_Wednesday_MnC = 0
lec_Thursday_MnC = 0
lec_Friday_MnC = 0
for slot in Monday_2:
    if "HM106(B) BK 280 2" in slot:
        pass
    else:
        for lister in lst_nest_MnC_1:
            if (lister[2]>0 and lister[3]!=False and lec_Monday_MnC<=2):
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lister[3] = False
                lec_Monday_MnC = lec_Monday_MnC+1
                break
        if (lec_Monday_MnC>=2):
                    break
for lister in lst_nest_MnC_1:
    if lister[2]>0:
        lister[3] = True
for slot in Tuesday_2:
    if "HM106(B) BK 280 2" in slot:
        pass
    else:
        for lister in lst_nest_MnC_1:
            if (lister[2]>0 and lister[3]!=False and lec_Tuesday_MnC<=2):
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lister[3] = False
                lec_Tuesday_MnC = lec_Tuesday_MnC+1
                break
        if (lec_Tuesday_MnC>=2):
                    break
for lister in lst_nest_MnC_1:
    if lister[2]>0:
        lister[3] = True
for slot in Wednesday_2:
    if "HM106(B) BK 280 2" in slot:
        pass
    else:
        for lister in lst_nest_MnC_1:
            if (lister[2]>0 and lister[3]!=False and lec_Wednesday_MnC<=2):
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lister[3] = False
                lec_Wednesday_MnC = lec_Wednesday_MnC+1
                break
        if (lec_Wednesday_MnC>=2):
                    break
for lister in lst_nest_MnC_1:
    if lister[2]>0:
        lister[3] = True
for slot in Thursday_2:
    if "HM106(B) BK 280 2" in slot:
        pass
    else:
        for lister in lst_nest_MnC_1:
            if (lister[2]>0 and lister[3]!=False and lec_Thursday_MnC<=2):
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lister[3] = False
                lec_Thursday_MnC = lec_Thursday_MnC+1
                break
        if (lec_Thursday_MnC>=2):
                    break
for lister in lst_nest_MnC_1:
    if lister[2]>0:
        lister[3] = True
for slot in Friday_2:
    if "HM106(B) BK 280 2" in slot:
        pass
    else:
        for lister in lst_nest_MnC_1:
            if (lister[2]>0 and lister[3]!=False and lec_Friday_MnC<=2):
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lister[3] = False
                lec_Friday_MnC = lec_Friday_MnC+1
                break
        if (lec_Friday_MnC>=2):
                    break
for lister in lst_nest_MnC_1:
    if lister[2]>0:
        lister[3] = True
lec_Monday_MnC_3 = 0
lec_Tuesday_MnC_3 = 0
lec_Wednesday_MnC_3 = 0
lec_Thursday_MnC_3 = 0
lec_Friday_MnC_3 = 0
for slot in Monday_2:
    for lister in lst_nest_MnC_4:
        if (lister[2]>0 and lister[3]!=False and lec_Monday_MnC_3<=4):
            slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            lec_Monday_MnC_3 = lec_Monday_MnC_3+1
            break
    if (lec_Monday_MnC>=4):
        break
for lister in lst_nest_MnC_4:
    if lister[2]>0:
        lister[3] = True
for slot in Tuesday_2:
    for lister in lst_nest_MnC_4:
        if (lister[2]>0 and lister[3]!=False and lec_Tuesday_MnC_3<=4):
            slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            lec_Tuesday_MnC_3 = lec_Tuesday_MnC_3+1
            break
    if (lec_Tuesday_MnC_3>=3):
        break
for lister in lst_nest_MnC_4:
    if lister[2]>0:
        lister[3] = True
for slot in Wednesday_2:
    for lister in lst_nest_MnC_4:
        if (lister[2]>0 and lister[3]!=False and lec_Wednesday_MnC_3<=6):
            slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            lec_Wednesday_MnC_3 = lec_Wednesday_MnC_3+1
            break
    if (lec_Wednesday_MnC_3>=4):
        break
for lister in lst_nest_MnC_4:
    if lister[2]>0:
        lister[3] = True
for slot in Thursday_2:
    for lister in lst_nest_MnC_4:
        if (lister[2]>0 and lister[3]!=False and lec_Thursday_MnC_3<=4):
            slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            lec_Thursday_MnC_3 = lec_Thursday_MnC_3+1
            break
    if (lec_Thursday_MnC>=4):
        break
for lister in lst_nest_MnC_4:
    if lister[2]>0:
        lister[3] = True
for slot in Friday_2:
    for lister in lst_nest_MnC_4:
        if (lister[2]>0 and lister[3]!=False and lec_Friday_MnC_3<=4):
            slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            lec_Friday_MnC_3 = lec_Friday_MnC_3+1
            break
    if (lec_Friday_MnC_3>=4):
        break
for lister in lst_nest_MnC_4:
    if lister[2]>0:
        lister[3] = True
for lister in lst_nest_MnC_4:
    if (lister[3]==True):
        lec_Monday_MnC_3 = 0
        lec_Tuesday_MnC_3 = 0
        lec_Wednesday_MnC_3 = 0
        lec_Thursday_MnC_3 = 0
        lec_Friday_MnC_3 = 0
        for slot in Monday_2:
            loopbreaker = 0
            for element in lst_nest_MnC_4:
                if element in slot:
                    loopbreaker = 1
            if (loopbreaker==1):
                break
            for lister in lst_nest_MnC_4:
                if (lister[2]>0 and lister[3]!=False and lec_Monday_MnC_3<=4):
                    slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                    lister[2] = lister[2]-1
                    lister[3] = False
                lec_Monday_MnC_3 = lec_Monday_MnC_3+1
                break
        if (lec_Monday_MnC>=4):
            break
    for lister in lst_nest_MnC_4:
        if lister[2]>0:
            lister[3] = True
    for slot in Tuesday_2:
        loopbreaker = 0
        for element in lst_nest_MnC_4:
                humari_string = element[0]+" "+element[1]+" "+str(element[4])+" "+element[5]
                if humari_string in slot:
                    loopbreaker = 1
        for lister in lst_nest_MnC_4:
            if (lister[2]>0 and lister[3]!=False and lec_Tuesday_MnC_3<=4 and loopbreaker!=1):
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lister[3] = False
                lec_Tuesday_MnC_3 = lec_Tuesday_MnC_3+1
                break
        if (lec_Tuesday_MnC_3>=3):
            break
    for lister in lst_nest_MnC_4:
        if lister[2]>0:
            lister[3] = True
    for slot in Wednesday_2:
        loopbreaker = 0
        for element in lst_nest_MnC_4:
                humari_string = element[0]+" "+element[1]+" "+str(element[4])+" "+element[5]
                if humari_string in slot:
                    loopbreaker = 1
        for lister in lst_nest_MnC_4:
            if (lister[2]>0 and lister[3]!=False and lec_Wednesday_MnC_3<=6 and loopbreaker!=1):
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lister[3] = False
                lec_Wednesday_MnC_3 = lec_Wednesday_MnC_3+1
                break
        if (lec_Wednesday_MnC_3>=4):
            break
    for lister in lst_nest_MnC_4:
        if lister[2]>0:
            lister[3] = True
    for slot in Thursday_2:
        loopbreaker = 0
        for element in lst_nest_MnC_4:
                humari_string = element[0]+" "+element[1]+" "+str(element[4])+" "+element[5]
                if humari_string in slot:
                    loopbreaker = 1
        for lister in lst_nest_MnC_4:
            if (lister[2]>0 and lister[3]!=False and lec_Thursday_MnC_3<=4 and loopbreaker!=1):
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lister[3] = False
                lec_Thursday_MnC_3 = lec_Thursday_MnC_3+1
                break
        if (lec_Thursday_MnC>=4):
            break
    for lister in lst_nest_MnC_4:
        if lister[2]>0:
            lister[3] = True
    for slot in Friday_2:
        loopbreaker = 0
        for element in lst_nest_MnC_4:
                humari_string = element[0]+" "+element[1]+" "+str(element[4])+" "+element[5]
                if humari_string in slot:
                    loopbreaker = 1
        for lister in lst_nest_MnC_4:
            if (lister[2]>0 and lister[3]!=False and lec_Friday_MnC_3<=4 and loopbreaker!=1):
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lister[3] = False
                lec_Friday_MnC_3 = lec_Friday_MnC_3+1
                break
        if (lec_Friday_MnC_3>=4):
            break
    for lister in lst_nest_MnC_4:
        if lister[2]>0:
            lister[3] = True
lec_Monday_MnC_5 = 0
lec_Tuesday_MnC_5 = 0
lec_Wednesday_MnC_5 = 0
lec_Thursday_MnC_5 = 0
lec_Friday_MnC_5 = 0
for slot in Monday_2:
    for lister in lst_nest_MnC_6:
        if (lister[2]>0 and lister[3]!=False and lec_Monday_MnC_5<=2):
            slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            lec_Monday_MnC_5 = lec_Monday_MnC_5+1
            break
    if (lec_Monday_MnC>=2):
        break
for lister in lst_nest_MnC_6:
    if lister[2]>0:
        lister[3] = True
for slot in Tuesday_2:
    for lister in lst_nest_MnC_6:
        if (lister[2]>0 and lister[3]!=False and lec_Tuesday_MnC_5<=2):
            slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            lec_Tuesday_MnC_5 = lec_Tuesday_MnC_5+1
            break
    if (lec_Tuesday_MnC>=2):
        break
for lister in lst_nest_MnC_6:
    if lister[2]>0:
        lister[3] = True
for slot in Wednesday_2:
    for lister in lst_nest_MnC_6:
        if (lister[2]>0 and lister[3]!=False and lec_Wednesday_MnC_5<=4):
            slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            lec_Wednesday_MnC_5 = lec_Wednesday_MnC_5+1
            break
    if (lec_Wednesday_MnC>=4):
        break
for lister in lst_nest_MnC_6:
    if lister[2]>0:
        lister[3] = True
for slot in Thursday_2:
    for lister in lst_nest_MnC_6:
        if (lister[2]>0 and lister[3]!=False and lec_Thursday_MnC_5<=4):
            slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            lec_Thursday_MnC_5 = lec_Thursday_MnC_5+1
            break
    if (lec_Thursday_MnC>=4):
        break
for lister in lst_nest_MnC_6:
    if lister[2]>0:
        lister[3] = True
for slot in Friday_2:
    for lister in lst_nest_MnC_6:
        if (lister[2]>0 and lister[3]!=False and lec_Friday_MnC_5<=4):
            slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            lister[2] = lister[2]-1
            lister[3] = False
            lec_Friday_MnC_5 = lec_Friday_MnC_5+1
            break
    if (lec_Friday_MnC>=4):
        break
for lister in lst_nest_MnC_6:
    if lister[2]>0:
        lister[3] = True
for slot in Monday_2:
    if "HM106(B) BK 280 2" in slot:
        pass
    elif "IT205(B) AR2 190 2" in slot:
        pass
    elif "SC217(B) GD 190 2" in slot:
        pass
    elif "IC121(B) PK 190 2" in slot:
        pass
    else:
        for lister in lst_nest_EvD:
            if (lister[2]>0 and lister[3]!=False and len(slot)<5):
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lister[3] = False
                break
for lister in lst_nest_EvD:
    if (lister[2]>0):
        lister[3] = True
for slot in Tuesday_2:
    if "HM106(B) BK 280 2" in slot:
        pass
    elif "IT205(B) AR2 190 2" in slot:
        pass
    elif "SC217(B) GD 190 2" in slot:
        pass
    elif "IC121(B) PK 190 2" in slot:
        pass
    else:
        for lister in lst_nest_EvD:
            if (lister[2]>0 and lister[3]!=False and len(slot)<5): 
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lister[3] = False
                break
for lister in lst_nest_EvD:
    if (lister[2]>0):
        lister[3] = True
for slot in Wednesday_2:
    if "HM106(B) BK 280 2" in slot:
        pass
    elif "IT205(B) AR2 190 2" in slot:
        pass
    elif "SC217(B) GD 190 2" in slot:
        pass
    elif "IC121(B) PK 190 2" in slot:
        pass
    else:
        for lister in lst_nest_EvD:
            if (lister[2]>0 and lister[3]!=False and len(slot)<5):
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lister[3] = False
                break
for lister in lst_nest_EvD:
    if (lister[2]>0):
        lister[3] = True
for slot in Thursday_2:
    if "HM106(B) BK 280 2" in slot:
        pass
    elif "IT205(B) AR2 190 2" in slot:
        pass
    elif "SC217(B) GD 190 2" in slot:
        pass
    elif "IC121(B) PK 190 2" in slot:
        pass
    else:
        for lister in lst_nest_EvD:
            if (lister[2]>0 and lister[3]!=False and len(slot)<5):
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lister[3] = False
                break
for lister in lst_nest_EvD:
    if (lister[2]>0):
        lister[3] = True
for slot in Friday_2:
    if "HM106(B) BK 280 2" in slot:
        pass
    elif "IT205(B) AR2 190 2" in slot:
        pass
    elif "SC217(B) GD 190 2" in slot:
        pass
    elif "IC121(B) PK 190 2" in slot:
        pass
    else:
        for lister in lst_nest_EvD:
            if (lister[2]>0 and lister[3]!=False and len(slot)<5):
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                lister[2] = lister[2]-1
                lister[3] = False
                break
for lister in lst_nest_EvD:
    if (lister[2]>0):
        lister[3] = True
lst_elective_1 = ["IE406","SM",3,True,90,"-"]
lst_elective_2 = ["IE410","TKM",3,True,20,"-"]
lst_elective_3 = ["IE411","AMM",3,True,20,"-"]
lst_elective_4 = ["IE403","PKS",3,True,20,"-"]
lst_elective_5 = ["IE404","MK",3,True,20,"-"]

lst_elective_6 = ["CT476","PK",3,True,20,"-"]
lst_elective_7 = ["CT548","MK2",3,True,20,"-"]
lst_elective_8 = ["CT547","AJ",3,True,20,"-"]
lst_elective_9 = ["CT491","DKG",3,True,20,"-"]
lst_elective_10 = ["CT491","RLD",3,True,20,"-"]
lst_elective_11 = ["CT550","DNC",3,True,20,"-"]
lst_elective_12 = ["EL516","SR",3,True,20,"-"]
lst_elective_13 = ["EL464","RP",3,True,20,"-"]
lst_elective_14 = ["EL527","VSP",3,True,20,"-"]
lst_elective_15 = ["EL495","TKM",3,True,20,"-"]
lst_elective_16 = ["EL496","SK",3,True,20,"-"]

lst_elective_17 = ["IT422","RM",3,True,20,"-"]
lst_elective_18 = ["IT457","LS",3,True,20,"-"]
lst_elective_19 = ["IT492","AR2",3,True,20,"-"]
lst_elective_20 = ["IT499","PB",3,True,20,"-"]
lst_elective_21 = ["IT590","TB",3,True,20,"-"]
lst_elective_22 = ["IT559","PKS",3,True,20,"-"]
lst_elective_23 = ["IT504","MB",3,True,20,"-"]
lst_elective_24 = ["IT412","SDG",3,True,20,"-"]
lst_elective_25 = ["IT583","BG",3,True,20,"-"]
lst_elective_26 = ["IT544","MLD",3,True,20,"-"]
lst_elective_27 = ["IT495","GP",3,True,20,"-"]
lst_elective_28 = ["IT584","RC",3,True,20,"-"]
lst_elective_29 = ["IT561","ST",3,True,20,"-"]

lst_elective_30 = ["SC402","MKG",3,True,20,"-"]
lst_elective_31 = ["SC471","MT",3,True,20,"-"]
lst_elective_32 = ["SC474","AKR",3,True,20,"-"]
lst_elective_33 = ["SC472","Gaurav_Singh",3,True,20,"-"]

lst_elective_34 = ["HM327","MM",3,True,20,"-"]
lst_elective_35 = ["HM432","N_Banerjee",3,True,20,"-"]
lst_elective_36 = ["HM402","SJ",3,True,20,"-"]
lst_elective_37 = ["HM488","Amishal_Modi",3,True,20,"-"]
lst_elective_38 = ["HM489","Cyril_Jos",3,True,20,"-"]
lst_elective_39 = ["HM481","BK",3,True,20,"-"]
lst_elective_40 = ["HM492","JJ",3,True,20,"-"]

lst_nest_elective_1 = [lst_elective_1,lst_elective_2,lst_elective_3,lst_elective_4,lst_elective_5]

lst_nest_elective_2 = [lst_elective_6,lst_elective_7,lst_elective_8,lst_elective_9,lst_elective_10,
                       lst_elective_11,lst_elective_12,lst_elective_13,lst_elective_14,lst_elective_15,
                       lst_elective_16]

lst_nest_elective_3 = [lst_elective_17,lst_elective_18,lst_elective_19,lst_elective_20,
                       lst_elective_21,lst_elective_22,lst_elective_23,lst_elective_24,
                       lst_elective_25,lst_elective_26,lst_elective_27,lst_elective_28,
                       lst_elective_29]

lst_nest_elective_4 = [lst_elective_30,lst_elective_31,lst_elective_32,lst_elective_33]

lst_nest_elective_5 = [lst_elective_34,lst_elective_35,lst_elective_36,lst_elective_37,
                       lst_elective_38,lst_elective_39,lst_elective_40]

for slot in Friday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Friday_2)<5):
        new_slot = []
        Friday_2.append(new_slot)
        for lister in lst_nest_elective_1:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_1:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<5 and restricted_condition!=1):
            for lister in lst_nest_elective_1:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_1:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_1:
    if (lister[2]>0):
        lister[3] = True
for slot in Thursday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Thursday_2)<5):
        new_slot = []
        Thursday_2.append(new_slot)
        for lister in lst_nest_elective_1:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_1:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<5 and restricted_condition!=1):
            for lister in lst_nest_elective_1:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_1:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_1:
    if (lister[2]>0):
        lister[3] = True
for slot in Wednesday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Wednesday_2)<5):
        new_slot = []
        Wednesday_2.append(new_slot)
        for lister in lst_nest_elective_1:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_1:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<5 and restricted_condition!=1):
            for lister in lst_nest_elective_1:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_1:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_1:
    if (lister[2]>0):
        lister[3] = True
for slot in Tuesday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Tuesday_2)<5):
        new_slot = []
        Tuesday_2.append(new_slot)
        for lister in lst_nest_elective_1:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_1:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<=5 and restricted_condition!=1):
            for lister in lst_nest_elective_1:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_1:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_1:
    if (lister[2]>0):
        lister[3] = True
for slot in Monday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Monday_2)<5):
        new_slot = []
        Monday_2.append(new_slot)
        for lister in lst_nest_elective_1:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_1:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[3]!=False and lister[2]>0 and len(slot)<5 and restricted_condition!=1):
            for lister in lst_nest_elective_1:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_1:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_1:
    if (lister[2]>0):
        lister[3] = True
# -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
for slot in Friday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Friday_2)<5):
        new_slot = []
        Friday_2.append(new_slot)
        for lister in lst_nest_elective_2:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_2:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<5 and restricted_condition!=1):
            for lister in lst_nest_elective_2:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_2:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_2:
    if (lister[2]>0):
        lister[3] = True
for slot in Thursday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Thursday_2)<5):
        new_slot = []
        Thursday_2.append(new_slot)
        for lister in lst_nest_elective_2:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_2:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<5 and restricted_condition!=1):
            for lister in lst_nest_elective_2:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_2:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_2:
    if (lister[2]>0):
        lister[3] = True
for slot in Wednesday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Wednesday_2)<5):
        new_slot = []
        Wednesday_2.append(new_slot)
        for lister in lst_nest_elective_2:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_2:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<5 and restricted_condition!=1):
            for lister in lst_nest_elective_2:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_2:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_2:
    if (lister[2]>0):
        lister[3] = True
for slot in Tuesday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Tuesday_2)<5):
        new_slot = []
        Tuesday_2.append(new_slot)
        for lister in lst_nest_elective_2:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_2:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<5 and restricted_condition!=1):
            for lister in lst_nest_elective_2:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_2:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_2:
    if (lister[2]>0):
        lister[3] = True
for slot in Monday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Monday_2)<5):
        new_slot = []
        Monday_2.append(new_slot)
        for lister in lst_nest_elective_2:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_2:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[3]!=False and lister[2]>0 and len(slot)<=5 and restricted_condition!=1):
            for lister in lst_nest_elective_2:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_2:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_3:
    if (lister[2]>0):
        lister[3] = True
# --------------------------------------------------------------------------------------------------------------------------------------------------------------
for slot in Friday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Friday_2)<5):
        new_slot = []
        Friday_2.append(new_slot)
        for lister in lst_nest_elective_3:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_3:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<=6 and restricted_condition!=1):
            for lister in lst_nest_elective_3:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_3:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_3:
    if (lister[2]>0):
        lister[3] = True
for slot in Thursday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Thursday_2)<5):
        new_slot = []
        Thursday_2.append(new_slot)
        for lister in lst_nest_elective_3:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_3:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<=6 and restricted_condition!=1):
            for lister in lst_nest_elective_3:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_3:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_3:
    if (lister[2]>0):
        lister[3] = True
for slot in Wednesday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==5 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Wednesday_2)<5):
        new_slot = []
        Wednesday_2.append(new_slot)
        for lister in lst_nest_elective_3:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_3:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<=6 and restricted_condition!=1):
            for lister in lst_nest_elective_3:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_3:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_3:
    if (lister[2]>0):
        lister[3] = True
for slot in Tuesday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Tuesday_2)<5):
        new_slot = []
        Tuesday_2.append(new_slot)
        for lister in lst_nest_elective_3:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_3:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<=6 and restricted_condition!=1):
            for lister in lst_nest_elective_3:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_3:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_3:
    if (lister[2]>0):
        lister[3] = True
for slot in Monday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==5 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Monday_2)<5):
        new_slot = []
        Monday_2.append(new_slot)
        for lister in lst_nest_elective_3:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_3:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[3]!=False and lister[2]>0 and len(slot)<=6 and restricted_condition!=1):
            for lister in lst_nest_elective_3:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_3:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_3:
    if (lister[2]>0):
        lister[3] = True
# --------------------------------------------------------------------------------------------------------------------------------------------------------------
for slot in Friday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==5 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Friday_2)<5):
        new_slot = []
        Friday_2.append(new_slot)
        for lister in lst_nest_elective_4:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_4:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<=6 and restricted_condition!=1):
            for lister in lst_nest_elective_4:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_4:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_4:
    if (lister[2]>0):
        lister[3] = True
for slot in Thursday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Thursday_2)<5):
        new_slot = []
        Thursday_2.append(new_slot)
        for lister in lst_nest_elective_4:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_4:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<=6 and restricted_condition!=1):
            for lister in lst_nest_elective_4:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_4:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_4:
    if (lister[2]>0):
        lister[3] = True
for slot in Wednesday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Wednesday_2)<5):
        new_slot = []
        Wednesday_2.append(new_slot)
        for lister in lst_nest_elective_4:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_4:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<=6 and restricted_condition!=1):
            for lister in lst_nest_elective_4:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_4:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_4:
    if (lister[2]>0):
        lister[3] = True
for slot in Tuesday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Tuesday_2)<5):
        new_slot = []
        Tuesday_2.append(new_slot)
        for lister in lst_nest_elective_4:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_4:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<=6 and restricted_condition!=1):
            for lister in lst_nest_elective_4:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_4:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_4:
    if (lister[2]>0):
        lister[3] = True
for slot in Monday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]==6 and (naya_lst[0])[0:2]!="MC"):
            restricted_condition = restricted_condition+1
            break
    if (len(Monday_2)<5):
        new_slot = []
        Monday_2.append(new_slot)
        for lister in lst_nest_elective_4:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_4:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!=6 or (new_lst_evaluation[0])[0:2]=="MC") and lister[3]!=False and lister[2]>0 and len(slot)<=6 and restricted_condition!=1):
            for lister in lst_nest_elective_4:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_4:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_4:
    if (lister[2]>0):
        lister[3] = True
# ----------------------------------------------------------------------------------------------------------------------------------------------------------------
for slot in Friday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]=='6' and (naya_lst[3]=='6' and (naya_lst[0])[0:2]!="MC")):
            restricted_condition = restricted_condition+1
            break
    if (len(Friday_2)<5):
        new_slot = []
        Friday_2.append(new_slot)
        for lister in lst_nest_elective_5:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_5:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        for lister in lst_nest_elective_5:
            if (lister[2]>0 and lister[3]!=False and len(slot)<=7 and restricted_condition!=1):
                for lister in lst_nest_elective_5:
                    slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
                for lister in lst_nest_elective_5:
                    lister[2] = lister[2]-1
                    lister[3] = False
for lister in lst_nest_elective_5:
    if (lister[2]>0):
        lister[3] = True
for slot in Thursday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]=='5' and (naya_lst[3]=='6' and (naya_lst[0])[0:2]!="MC")):
            restricted_condition = restricted_condition+1
            break
    if (len(Thursday_2)<5):
        new_slot = []
        Thursday_2.append(new_slot)
        for lister in lst_nest_elective_5:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_5:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        for lister in lst_nest_elective_5:
            if ((new_lst_evaluation[2]!='6' or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<=7 and restricted_condition!=1):
                for lister in lst_nest_elective_5:
                    slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
                for lister in lst_nest_elective_5:
                    lister[2] = lister[2]-1
                    lister[3] = False
for lister in lst_nest_elective_5:
    if (lister[2]>0):
        lister[3] = True
for slot in Wednesday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]=='6' and (naya_lst[3]=='6' and (naya_lst[0])[0:2]!="MC")):
            restricted_condition = restricted_condition+1
            break
    if (len(Wednesday_2)<5):
        new_slot = []
        Wednesday_2.append(new_slot)
        for lister in lst_nest_elective_5:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_5:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!='6' or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<=7 and restricted_condition!=1):
            for lister in lst_nest_elective_5:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
            for lister in lst_nest_elective_5:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_5:
    if (lister[2]>0):
        lister[3] = True
for slot in Tuesday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]=='6' and (naya_lst[3]=='6' and (naya_lst[0])[0:2]!="MC")):
            restricted_condition = restricted_condition+1
            break
    if (len(Tuesday_2)<5):
        new_slot = []
        Tuesday_2.append(new_slot)
        for lister in lst_nest_elective_5:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_5:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!='6' or (new_lst_evaluation[0])[0:2]=="MC") and lister[2]>0 and lister[3]!=False and len(slot)<=7 and restricted_condition!=1):
            for lister in lst_nest_elective_5:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_5:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_5:
    if (lister[2]>0):
        lister[3] = True
for slot in Monday_2:
    restricted_condition = 0
    for classes in slot:
        naya_lst = classes.split(" ")
        if (naya_lst[3]=='6' and (naya_lst=='6' and (naya_lst[0])[0:2]!="MC")):
            restricted_condition = restricted_condition+1
            break
    if (len(Monday_2)<5):
        new_slot = []
        Monday_2.append(new_slot)
        for lister in lst_nest_elective_5:
            new_slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5])
        for lister in lst_nest_elective_5:
            lister[2] = lister[2]-1
            lister[3] = False
        break
    for lectures in slot:
        new_lst_evaluation = lectures.split(" ")
        if ((new_lst_evaluation[2]!='5' or (new_lst_evaluation[0])[0:2]=="MC") and lister[3]!=False and lister[2]>0 and len(slot)<=7 and restricted_condition!=1):
            for lister in lst_nest_elective_5:
                slot.append(lister[0]+" "+lister[1]+" "+str(lister[4])+" "+lister[5]) 
            for lister in lst_nest_elective_5:
                lister[2] = lister[2]-1
                lister[3] = False
for lister in lst_nest_elective_5:
    if (lister[2]>0):
        lister[3] = True
# ----------------------------------------------------------------------------------------------------------------------------------------------------------------
room = {"CEP212":[30,True],"CEP210":[30,True],"CEP109":[36,True],
        "CEP107":[36,True],"CEP105":[48,True],"CEP104":[48,True],
        "CEP003":[48,True],"CEP205":[60,True],"CEP206":[60,True],
        "CEP211":[80,True],"CEP202":[80,True],"CEP203":[80,True],
        "CEP103":[110,True],"CEP106":[120,True],"CEP108":[120,True],
        "CEP110":[182,True],"CEP102":[190,True],
        "LT01":[281,True],"LT02":[318,True],"LT03":[370,True]}
slot_number = "1"
lst_instructor = []
all_instructor = []
for lister in Days_of_Week:
    for slot in lister:
        if (slot_number=="1"):
            print("Monday 8:00 - 8:50")
            print()
        elif (slot_number=="2"):
            print("Monday 9:00 - 9:50")
            print()
        elif (slot_number=="3"):
            print("Monday 10:00 - 10:50")
            print()
        elif (slot_number=="4"):
            print("Monday 11:00 - 11:50")
            print()
        elif (slot_number=="5"):
            print("Monday 12:00 - 12:50")
            print()
        elif (slot_number=="6"):
            print("Tuesday 8:00 - 8:50")
            print()
        elif (slot_number=="7"):
            print("Tuesday 9:00 - 9:50")
            print()
        elif (slot_number=="8"):
            print("Tuesday 10:00 - 10:50")
            print()
        elif (slot_number=="9"):
            print("Tuesday 11:00 - 11:50")
            print()
        elif (slot_number=="10"):
            print("Tuesday 12:00 - 12:50")
            print()
        elif (slot_number=="11"):
            print("Wednesday 8:00 - 8:50")
            print()
        elif (slot_number=="12"):
            print("Wednesday 9:00 - 9:50")
            print()
        elif (slot_number=="13"):
            print("Wednesday 10:00 - 10:50")
            print()
        elif (slot_number=="14"):
            print("Wednesday 11:00 - 11:50")
            print()
        elif (slot_number=="15"):
            print("Wednesday 12:00 - 12:50")
            print()
        elif (slot_number=="16"):
            print("Thursday 8:00 - 8:50")
            print()
        elif (slot_number=="17"):
            print("Thursday 9:00 - 9:50")
            print()
        elif (slot_number=="18"):
            print("Thursday 10:00 - 10:50")
            print()
        elif (slot_number=="19"):
            print("Thursday 11:00 - 11:50")
            print()
        elif (slot_number=="20"):
            print("Thursday 12:00 - 12:50")
            print()
        elif (slot_number=="21"):
            print("Friday 8:00 - 8:50")
            print()
        elif (slot_number=="22"):
            print("Friday 9:00 - 9:50")
            print()
        elif (slot_number=="23"):
            print("Friday 10:00 - 10:50")
            print()
        elif (slot_number=="24"):
            print("Friday 11:00 - 11:50")
            print()
        elif (slot_number=="25"):
            print("Friday 12:00 - 12:50")
            print()
        
        for lecture in slot:
            lst_of_lecture = lecture.split(" ")
            for classroom in room:
                if ((int(lst_of_lecture[2])-10)<=(room[classroom][0]) and room[classroom][1]!=False):
                    sting = lst_of_lecture[0]+" "+lst_of_lecture[1]+" "+lst_of_lecture[3]+" "+classroom+" "+str(slot_number)
                    lst_instructor.append(sting)
                    all_instructor.append(lst_of_lecture[1])
                    print(sting)
                    room[classroom][1] = False
                    break
        print("----------------------------------------")
        slot_number = int(slot_number)+1
        slot_number = str(slot_number)
        for classroom in room:
            room[classroom][1] = True# print(lst_instructor)
set_instructor = set(all_instructor)
all_instructor = list(set_instructor)       
# print(all_instructor)  
for teacher in all_instructor:
    print(teacher)
    for string2 in lst_instructor:
        lst_slot = string2.split(" ")
        if teacher in lst_slot:
            for strings in lst_slot:
                print(strings,end=" ")
            if (lst_slot[-1]=="1"):
                print("Monday 8:00 - 8:50 Slot 1")
            elif (lst_slot[-1]=="2"):
                print("Monday 9:00 - 9:50 Slot 2")
            elif (lst_slot[-1]=="3"):
                print("Monday 10:00 - 10:50 Slot 3")
            elif (lst_slot[-1]=="4"):
                print("Monday 11:00 - 11:50 Slot 4")
            elif (lst_slot[-1]=="5"):
                print("Monday 12:00 - 12:50 Slot 5")
            elif (lst_slot[-1]=="6"):
                print("Tuesday 8:00 - 8:50 Slot 1")
            elif (lst_slot[-1]=="7"):
                print("Tuesday 9:00 - 9:50 Slot 2")
            elif (lst_slot[-1]=="8"):
                print("Tuesday 10:00 - 10:50 Slot 3")
            elif (lst_slot[-1]=="9"):
                print("Tuesday 11:00 - 11:50 Slot 4")
            elif (lst_slot[-1]=="10"):
                print("Tuesday 12:00 - 12:50 Slot 5")
            elif (lst_slot[-1]=="11"):
                print("Wednesday 8:00 - 8:50 Slot 1")
            elif (lst_slot[-1]=="12"):
                print("Wednesday 9:00 - 9:50 Slot 2")
            elif (lst_slot[-1]=="13"):
                print("Wednesday 10:00 - 10:50 Slot 3")
            elif (lst_slot[-1]=="14"):
                print("Wednesday 11:00 - 11:50 Slot 4")
            elif (lst_slot[-1]=="15"):
                print("Wednesday 12:00 - 12:50 Slot 5")
            elif (lst_slot[-1]=="16"):
                print("Thursday 8:00 - 8:50 Slot 1")
            elif (lst_slot[-1]=="17"):
                print("Thursday 9:00 - 9:50 Slot 2")
            elif (lst_slot[-1]=="18"):
                print("Thursday 10:00 - 10:50 Slot 3")
            elif (lst_slot[-1]=="19"):
                print("Thursday 11:00 - 11:50 Slot 4")
            elif (lst_slot[-1]=="20"):
                print("Thursday 12:00 - 12:50 Slot 5")
            elif (lst_slot[-1]=="21"):
                print("Friday 8:00 - 8:50 Slot 1")
            elif (lst_slot[-1]=="22"):
                print("Friday 9:00 - 9:50 Slot 2")
            elif (lst_slot[-1]=="23"):
                print("Friday 10:00 - 10:50 Slot 3")
            elif (lst_slot[-1]=="24"):
                print("Friday 11:00 - 11:50 Slot 4")
            elif (lst_slot[-1]=="25"):
                print("Friday 12:00 - 12:50 Slot 5")
    print("------------------------------------")