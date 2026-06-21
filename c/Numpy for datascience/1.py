python_list = [1,2,3,4,5]
print(python_list)

import numpy as np

##arr = np.array([1,2,3,6])

#print(arr.dtype)
#int_arr = arr.astype(int)

#print(int_arr)
#print(int_arr.dtype)

#print(arr+5)
#print(arr*2)
#print(arr**2)

#print(np.sum(arr))
#print(np.mean(arr))
#print(np.min(arr))
#print(np.max(arr))
#print(np.std(arr))
#print(np.var(arr))

arr=np.array([1,2,3,4,5,6])
#print(arr[0])  ///indexing starts from 0
#print(arr[2])
#print(arr[-1])  ///last element

"""print(arr[1:5])  # ek se 4 tkk chlega
print(arr[ :4])  ##o to3 chlega 
print(arr[ : : 2]) do step se chlega 
print(arr[ : : -1]) reverse krdega array ko
"""
#print(arr[arr>2.5])  filtering
"""reshaped_arr=arr.reshape(2,3)
print(reshaped_arr)

arr_2d=np.array([[1,2,3],[4,5,6]])
print(arr_2d.ravel())
print(arr_2d.flatten())


import numpy as np
arr=np.array([1,2,3,4,5,6])
new_arr=np.insert(arr,2,9)
print(new_arr)

import numpy as np
arr=np.array([[1,2],[3,4]])
new_arr=np.insert(arr,1,[5,6],axis=1)
print(new_arr)


import numpy as np
arr=np.array([10,20,30,40])
new_arr=np.append(arr,[40,50,60])
print(new_arr)

arr1=np.array([1,2,3])
arr2=np.array([4,5,6])
new_arr=np.concatenate((arr1,arr2))
print(new_arr)
new_arr1=np.delete(arr1,0)
print(new_arr1)

print(np.split(arr,2))
discount=10
final_prices=arr-(arr*discount/100)
print(final_prices)
result=arr*2
print(result)

matrix=np.array([[1,2,3],[4,5,6]])
vector=np.array(np.array([10,20,30]))
result=matrix+vector
print(result)


"""

print("kapil")

