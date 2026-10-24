class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>v={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int alam=0;
        int alad=0;
        int alem=0;
        int aled=0;
        int bbam=0;
        int bbad=0;
        int bbem=0;
        int bbed=0;
        int z=1;
        for(int i=0;i<5;i++){
            if(i<2){
                alam+=((arriveAlice[i]-'0')*pow(10,z));
                alem+=((leaveAlice[i]-'0')*pow(10,z));
                bbam+=((arriveBob[i]-'0')*pow(10,z));
                bbem+=((leaveBob[i]-'0')*pow(10,z));
                z--;
            }else if(i==2){
                z=1;
                continue;
            } 
            else{
                alad+=((arriveAlice[i]-'0')*pow(10,z));
                aled+=((leaveAlice[i]-'0')*pow(10,z));
                bbad+=((arriveBob[i]-'0')*pow(10,z));
                bbed+=((leaveBob[i]-'0')*pow(10,z));
                z--;
            }
        }
        int a=alad;
        int b=aled;
        int c=bbad;
        int d=bbed;
        for(int i=0;i<13;i++){
            if(i<alam){
                a+=v[i];
            }
            if(i<alem){
                b+=v[i];
            }
            if(i<bbam){
                c+=v[i];
            }
            if(i<bbem){
                d+=v[i];
            } 
        }
        if(b<c || d<a) return 0;
        if((a<=c && d<=b)|| (c<=a && b<=d)) return min(b-a,d-c)+1;
        if(c>=a) return b-c+1;
        if(c<=a) return d-a+1;
        return 0;
    }
};