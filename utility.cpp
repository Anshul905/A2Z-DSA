map< int , vector<pair<int,string>>  > m;
for (const auto &entry : myMap) {
    int key = entry.first;
    const vector<pair<int,string>> value = entry.second;
    
    cout << "Key: " << key << endl;

    // Iterate through the vector of pairs for each key
    for (const auto &pair : value) {
        int innerKey = pair.first;
        const string &innerValue = pair.second;
        cout << " Inner Key: " << innerKey << ", Inner Value: " << innerValue << endl;
    }

}





map< int , vector<int> > m;
for( auto it:m ){
    int w = it.first;
    vector<int> v = it.second;
    auto( int n:v )
        cout<<n;
}




// integer to string 

// string path = "";
// path += (to_string(10));
// path = 10




double x = 1.602176634;
double fractional;
double integral;

fractional = modf(x, &integral);

std::cout << "The fractional part of the given number is: " << fractional << "\n" << "The integral part of the given number is: " << integral << "\n";




to_string(1) 
stoi('1')

