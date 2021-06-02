SEATS = {1:'L',2:'M',3:'U',4:'L',5:'M',6:'U',7:'SL',8:'SU'}
TOTAL_NUM_SEATS = 72
NUM_ROWS = TOTAL_NUM_SEATS/len(SEATS)
choice = True
my_sub_list=[]
mylist=list(range(1,TOTAL_NUM_SEATS + 1))
#my_sub_list = [mylist[i:i + len(SEATS)] for i in xrange(0, len(mylist), len(SEATS))]
for i in range(0,len(SEATS)+1):
	#for j in range(0,len(SEATS)):
	#my_sub_list.append(i)
	my_sub_list.append(mylist[(8*i):(8*i)+len(SEATS)])
	print "i=",i
print my_sub_list