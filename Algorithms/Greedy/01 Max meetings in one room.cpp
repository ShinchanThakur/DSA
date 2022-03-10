//ONLY ONE MEETING CAN TAKE PLACE IN THE ROOM AT A TIME
//GIVEN THE START TIME AND END TIME FOR EACH MEET
//WHAT IS THE MAXIMUM NUMBER OF MEETINGS THAT CAN BE ALLOWED

struct meet{
    int start, end, pos;
};

bool static comparator(struct meet m1, struct meet m2){
    if(m1.end != m2.end)    return (m1.end < m2.end) ;
    return (m1.pos < m2.pos) ;
}

int maxMeetings(int start[], int end[], int n)
{
    struct meet meeting[n];
    for(int i=0; i<n; i++)
        meeting[i].start = start[i], meeting[i].end = end[i], meeting[i].pos = i+1;
    sort(meeting, meeting + n, comparator);

    vector<int> meetingOrder;
    meetingOrder.push_back(meeting[0].pos);

    int time = meeting[0].end, maxMeetings = 1;
    for(int i=1; i<n; i++)
        if(meeting[i].start > time){
            time = meeting[i].end;
            maxMeetings++;
            meetingOrder.push_back(meeting.pos);
        }
    return maxMeetings;
}

//Time complexity: O(nlogn)
//Space complexity: O(n)

//Problem Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#