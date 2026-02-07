def merge(arr,low,mid,high):
   temp = []
   left=low
   right = mid+1

   while left<=mid and right<=high:
      if arr[left] <= arr[right]:
        temp.append(arr[left])
        left+=1
      else:
        temp.append(arr[right])
        right+=1
   while left<=mid:
      arr.append(arr[left])
      left+=1
   while right<=high:
      arr.append(arr[right])
      right+=1
   for i in range(len(temp)):
      arr[i]=temp[i-low]    

def merge_sort(arr,low,high):
        mid=(low+high)//2
        merge_sort(arr,low,mid)
        merge_sort(arr,right,high)
        merge(arr,low,mid,high)

n=int(input("enter n"))
arr=[]
for i in range(n):
    arr.append(int(input("enter element")))
merge_sort(arr,0,n-1)
print("sorted array",arr)