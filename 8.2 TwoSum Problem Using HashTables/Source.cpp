#include<iostream>
#include <vector>
#include<unordered_map>
using namespace std;

 vector<int> twoSum(vector<int>& nums, int target) {
     // our hash table will be {key : index}
     unordered_map<int, int> map;
     vector<int> result ; 
    
     for(int i=0; i<nums.size() ; i++){
         // to check if key exists we use map.find[key]!=map.end() 
		 // as if map doesnt exists map.find return map.end

		 // Take care --> here we must check the target-nums[i] before inserting nums[i] in hash table 
		 // as there could be collisions as for ex [3 3] and target =6 
		 // this would fall if you put element first as 2nd three will overwrite the first one
         if(map.find(target-nums[i])!= map.end() ) {
             result.push_back(i);
             result.push_back(map[target-nums[i]] );
             return result;   
        }else
        {
            map[nums[i]]= i ;

        }
     }
     
     return result; 
 }    


 int main() {

	 // Runtime: 4 ms, faster than 99.58% of C++ online submissions for Two Sum.
	//  Memory Usage: 10.9 MB, less than 38.85% of C++ online submissions for Two Sum.
	// info about this solution by Me at leet code
	 // Go see Radix sort Lecture 7 where we solved this in 20ms which was better than O(n^2) nested loop
	 // however this is the best solution outthere

	 vector<int> nums; // {2,7,11,15}
	 nums.push_back(2);
	 nums.push_back(7);
	 nums.push_back(5);
	 nums.push_back(9);
	 int target = 9 ;

	vector<int> result = twoSum(nums,target) ;

	for(int i=0; i< result.size(); i++){
		cout << result[i]<<endl;
	}

	 system("pause") ;
 }