#include <iostream>
#include<cmath>

using namespace std;
 
struct University_In_Array
{
    int rank;
    string institution;
    string locationCode;
    string location;
    double arScore;
    string arRank;
    double erScore;
    string erRank;
    double fsrScore;
    string fsrRank;
    double cpfScore;
    string cpfRank;
    double ifrScore;
    string ifrRank;
    double isrScore;
    string isrRank;
    double irnScore;
    string irnRank;
    double gerScore;
    string gerRank;
    string scoreScaled;
};

class DynamicArray {
private:
    string* array = NULL;
    int size;
    int capacity;
     University_In_Array* university_array;
 
public:
    // Default constructor with size 1
    DynamicArray()
    {
        capacity = 1;
        size = 0;
        array = new string[capacity];
        university_array = new  University_In_Array[capacity];
    }
 
    // Taking size from the user
    DynamicArray(int capacity)
    {
        this->capacity = capacity;
        array = new string[capacity];
        size = 0;
        university_array = new  University_In_Array[capacity];
    }


//==================search===========================
 //insert - add new university
    void insertNewUniversityIntoArray(int rank, string institution, string locationCode, string location, double arScore, string arRank, double erScore, string erRank, double fsrScore, string fsrRank, double cpfScore, string cpfRank, double ifrScore, string ifrRank, double isrScore, string isrRank, double irnScore, string irnRank, double gerScore, string gerRank, string scoreScaled)
    {
        if(size == capacity) // if the array is full
        {
            capacity *= 2; // double the capacity
             University_In_Array* temp = new  University_In_Array[capacity]; // create a new array with the new capacity
            
            // copy the existing elements from the old array to the new array
            for(int i=0; i<size; i++)
            {
                temp[i] = university_array[i];
            }
            
            // delete the old array
            delete[] university_array;
            
            // point to the new array
            university_array = temp;
        }
        
        // add the new university at the end of the array
        university_array[size].rank = rank;
        university_array[size].institution = institution;
        university_array[size].locationCode = locationCode;
        university_array[size].location = location;
        university_array[size].arScore = arScore;
        university_array[size].arRank = arRank;
        university_array[size].erScore = erScore;
        university_array[size].erRank = erRank;
        university_array[size].fsrScore = fsrScore;
        university_array[size].fsrRank = fsrRank;
        university_array[size].cpfScore = cpfScore;
        university_array[size].cpfRank = cpfRank;
        university_array[size].ifrScore = ifrScore;
        university_array[size].ifrRank = ifrRank;
        university_array[size].isrScore = isrScore;
        university_array[size].isrRank = isrRank;
        university_array[size].irnScore = irnScore;
        university_array[size].irnRank = irnRank;
        university_array[size].gerScore = gerScore;
        university_array[size].gerRank = gerRank;
        university_array[size].scoreScaled = scoreScaled;
        
        size++; // increase the size of the array
    }

    void printUniversityInfoArray(int i){
        cout << "Rank          : " << university_array[i].rank << endl;    
        cout << "Institution   : " << university_array[i].institution << endl;
        cout << "Location Code : " << university_array[i].locationCode << endl;
        cout << "Location      : " << university_array[i].location << endl;
        cout << "AR Score      : " << university_array[i].arScore << endl;
        cout << "AR Rank       : " << university_array[i].arRank << endl;
        cout << "ER Score      : " << university_array[i].erScore << endl;
        cout << "ER Rank       : " << university_array[i].erRank << endl;
        cout << "FSR Score     : " << university_array[i].fsrScore << endl;
        cout << "FSR Rank      : " << university_array[i].fsrRank << endl;
        cout << "CPF Score     : " << university_array[i].cpfScore << endl;
        cout << "CPF Rank      : " << university_array[i].cpfRank << endl;
        cout << "IFR Score     : " << university_array[i].ifrScore << endl;
        cout << "IFR Rank      : " << university_array[i].ifrRank << endl;
        cout << "ISR Score     : " << university_array[i].isrScore << endl;
        cout << "ISR Rank      : " << university_array[i].isrRank << endl;
        cout << "IRN Score     : " << university_array[i].irnScore << endl;
        cout << "IRN Rank      : " << university_array[i].irnRank << endl;
        cout << "GER Score     : " << university_array[i].gerScore << endl;
        cout << "GER Rank      : " << university_array[i].gerRank << endl;
        cout << "Score Scaled  : " << university_array[i].scoreScaled << endl << endl;
}

    void printAll(){
        for (int i = 0; i < size; i++){
            cout << "Rank          : " << university_array[i].rank << endl;    
            cout << "Institution   : " << university_array[i].institution << endl;
            cout << "Location Code : " << university_array[i].locationCode << endl;
            cout << "Location      : " << university_array[i].location << endl;
            cout << "AR Score      : " << university_array[i].arScore << endl;
            cout << "AR Rank       : " << university_array[i].arRank << endl;
            cout << "ER Score      : " << university_array[i].erScore << endl;
            cout << "ER Rank       : " << university_array[i].erRank << endl;
            cout << "FSR Score     : " << university_array[i].fsrScore << endl;
            cout << "FSR Rank      : " << university_array[i].fsrRank << endl;
            cout << "CPF Score     : " << university_array[i].cpfScore << endl;
            cout << "CPF Rank      : " << university_array[i].cpfRank << endl;
            cout << "IFR Score     : " << university_array[i].ifrScore << endl;
            cout << "IFR Rank      : " << university_array[i].ifrRank << endl;
            cout << "ISR Score     : " << university_array[i].isrScore << endl;
            cout << "ISR Rank      : " << university_array[i].isrRank << endl;
            cout << "IRN Score     : " << university_array[i].irnScore << endl;
            cout << "IRN Rank      : " << university_array[i].irnRank << endl;
            cout << "GER Score     : " << university_array[i].gerScore << endl;
            cout << "GER Rank      : " << university_array[i].gerRank << endl;
            cout << "Score Scaled  : " << university_array[i].scoreScaled << endl << endl;
        }
}
    //linear search
    vector<int> linearSearch(string target_category, string target_value){
        vector<int> indices;
        bool isValid = false;
        for (int i=0; i<size; i++)
        {
            if (target_category == "uni_name"){
                if (university_array[i].institution == target_value)
                {
                    indices.push_back(i);
                    return indices;
                    isValid = true;
                }
            }  
            else if (target_category == "uni_location"){
                if (university_array[i].location == target_value)
                {
                    indices.push_back(i);
                    isValid = true;
                }
            }
        }
        if(isValid == false){cout << "Nothing found" << endl;}
        return indices;
    }

    //jump search
    vector<int> jumpSearch(string target_category, string target_value) {
        vector<int> indices;
        int step = sqrt(size); // calculate the step size
        int start = 0; // initialize the previous index
        int end = step;

        // jump forward in steps until the target value is found or the end of the array is reached
        if (target_category == "uni_name"){
            while (end < size && university_array[end].institution <= target_value)
            {
                start = end;
                end += step;
            }
        }
        if (target_category == "uni_location"){
            while (end < size && university_array[end].location <= target_value)
            {
                start = end;
                end += step;
            }
        }

        for (int i = start; i <= min(end, size-1); i++){
            if (university_array[i].institution == target_value)
            {
                indices.push_back(i);
                return indices; 
            } 
            else if (university_array[i].location == target_value)
            {
                indices.push_back(i);
            }   
        }
        return indices;  
    }

    void sortUniversityArray(string type) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (university_array[j].institution > university_array[j+1].institution && type == "uni_name") {
                swap(university_array[j], university_array[j+1]);
            }
            if (university_array[j].location > university_array[j+1].location && type == "uni_location") {
                swap(university_array[j], university_array[j+1]);
            }
        }
    }
}

//Normal User 
    int getSize() { return size; }
 
    int getCapacity() { return capacity; }
 
    void ppush_back(string value)
    {
        if (size == capacity) {
 
            growArray();
        }
        array[size] = value;
        size++;
    }
 
    // Increase the array size by double of current capacity
    void growArray()
    {
 
        // Creating new array of double size
        string* temp = new string[capacity * 2];
 
        capacity = capacity * 2;
        // copy element of old array in newly created array
        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }
 
        // Delete old array
        delete[] array;
 
        // Assign newly created temp array to original array
        array = temp;
    }
 
    void printArrayDetails()
    {
        for (int i = 0; i < size; i++) {
            cout << array[i] <<endl;
        }
    }
 
};