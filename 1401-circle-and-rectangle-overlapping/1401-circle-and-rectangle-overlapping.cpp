class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(xCenter<=x2 && xCenter>=x1 && yCenter<=y2 && yCenter>=y1 ) return true;
        int rcx1=0;
        int rcy1=0;
        rcx1=((x1-xCenter)*(x1-xCenter))<((x2-xCenter)*(x2-xCenter))?x1:x2;
        int ln=((y1-yCenter)*(y1-yCenter));
        for(int i=y1;i<=y2;i++){
            if(ln>=((i-yCenter)*(i-yCenter))){
                ln=((i-yCenter)*(i-yCenter));
                rcy1=i;
            }
        }
        int rcx2=0;
        int rcy2=0;
        rcy2=((y1-yCenter)*(y1-yCenter))<((y2-yCenter)*(y2-yCenter))?y1:y2;
        ln=((x1-xCenter)*(x1-xCenter));
        for(int i=x1;i<=x2;i++){
            if(ln>=((i-xCenter)*(i-xCenter))){
                ln=((i-xCenter)*(i-xCenter));
                rcx2=i;
            }
        }

        int mind=min((((rcx1-xCenter)*(rcx1-xCenter))+((rcy1-yCenter)*(rcy1-yCenter))),(((rcx2-xCenter)*(rcx2-xCenter))+((rcy2-yCenter)*(rcy2-yCenter))));
        if((radius*radius)>=mind) return true;
        return false;
    }
};