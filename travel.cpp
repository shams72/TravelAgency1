
#include "travel.h"
#include<QMessageBox>
#include<QDebug>
#include<stack>
#include<flight.h>
#include"algorithmen.cpp"
#include"QDate"
#include"car_rental.h"
#include"hotel.h"
#include<QDate>


template <class T, int maxVertices>
int Dfs(Graph<T, maxVertices> &g, int v, std::vector<int> &dep, int time) {// Tiefensuche ab Knoten v
    if (!g.isVisited(v)) {
        g.setColor(v, GREY); // als besucht markieren
        g.setStart(v, time); // Startzeitpunkt für Knoten setzen
        printVertex(g, v); // v besuchen
        int w = g.firstEdge(v);
        while (w != -1) { // alle Nachfolger von v bearbeiten
            if (!g.isVisited(w)) { // w noch nicht besucht
                time += 1;
                time = Dfs(g, w, dep, time); // Tiefensuche fuer w starten
            } else { //Kantenmarkierungen setzen
                if (g.getColor(w) == GREY)
                    g.setEdgeWeight(v, w, weightBackEdge); //Rückwärtskante
                else if (g.getColor(w) == BLACK) {
                    if (g.getStart(v) < g.getEnd(w))
                        g.setEdgeWeight(v, w, weightForwardEdge); // Forwardkante
                    else
                        g.setEdgeWeight(v, w, weightCrossEdge); //Crosskante
                }
            }
            w = g.nextEdge(v, w);
        }
        time += 1;
        g.setColor(v, BLACK);
        dep.push_back(v);
        g.setEnd(v, time);
        printVertex(g, v);
    }
    return time;
}


template <class T, int maxVertices>
void DepthFirstSearch(Graph<T, maxVertices> &g, std::vector<int> &dep) { // Tiefensuche
    int time = 1;
    setAllColor(g, WHITE); // Alle Knoten als unbesucht markieren
    int v = g.firstVertex();
    while (v != -1) {
        if (!g.isVisited(v)) { // v noch nicht besucht
            time = Dfs(g, v, dep, time); // Tiefensuche für v starten
            time += 1;
        }
        v = g.nextVertex(v);
    }
}






Travel::Travel()
{


}

bool Travel::checkroundtrip()
{
    //std::shared_ptr<Flightbooking> firstflight;
    //std::shared_ptr<Flightbooking> lastflight;

    std::vector<std::shared_ptr<Flightbooking>> flightbooking;


    for(int i=0;i<bokingliste.size();i++)
    {
        if(std::shared_ptr<Flightbooking> flight = std::dynamic_pointer_cast<Flightbooking>(bokingliste[dependencies[i]])){
            flightbooking.push_back(flight);

        }

    }

    if (flightbooking.front()->getfromdestination()==flightbooking.back()->gettodestination()){
        return true;
    }else{
        return false;
    }

    if(flightbooking.size()==0 ||flightbooking.size()==1){
        return false;
    }

}



void Travel::topologicalsort()
{

    int i=0;
    for(auto &buchung : bokingliste)
    {
        graph.insertVertex(i, buchung);
        i++;
    }


    int j=0;
    for(auto &booking : bokingliste)
    {
        if(booking->getPredecessor1()!=""){
            int saveindex = searchindex(booking->getid());
            int savepredecessor = searchindex(booking->getPredecessor1());
            graph.insertEdge(saveindex,savepredecessor);
        }
        if(booking->getPredecessor2()!=""){
            int saveindex = searchindex(booking->getid());
            int savepredecessor = searchindex(booking->getPredecessor2());
            graph.insertEdge(saveindex,savepredecessor);
        }
    }

    dependencies = sortiere();




 }

int Travel::searchindex(string id)
{
    for(int i=0;i<bokingliste.size();i++){
        if(bokingliste[i]->getid()==id){
            return i;
        }
    }return-1;
}


int Travel::gettravelid(){
    return id;
}

std::vector<std::shared_ptr<Booking> > Travel::getBokingliste()
{

    return bokingliste;
    std::vector<int> vk;
        // DepthFirstSearch(graph);

}

bool Travel::checkenoughhotels()
{
    std::vector<std::shared_ptr<Booking>>book;
    topologicalsort();


    for(int i=0;i<dependencies.size();i++){
        if(std::shared_ptr<Rentalcarreservation> rental =std::dynamic_pointer_cast<Rentalcarreservation>(bokingliste[dependencies[i]])){
            continue;
        }else{

            book.push_back(bokingliste[dependencies[i]]);

        }
    }

    for(int i=0;i<book.size()-1;i++){
        QDate toDate =QDate::fromString(QString::fromStdString(book[i]->gettodate()),"yyyyMMdd");
        QDate fromDate =QDate::fromString(QString::fromStdString(book[i+1]->getfromdate()),"yyyyMMdd");
        if(toDate.daysTo(fromDate)>0){
            return true;
        }


    }
    return false;

}

bool Travel::checknouselessrentalcar()
{

    topologicalsort();
    std::vector<std::shared_ptr<Booking>>book;
    topologicalsort();
    for(int i=0;i<bokingliste.size();i++){

        if(std::shared_ptr<Hotelreservation> hotel =std::dynamic_pointer_cast<Hotelreservation>(bokingliste[dependencies[i]])){
            continue;
        }


        else{
            book.push_back(bokingliste[dependencies[i]]);

        }
    }

    if(book.size()==0){
        return true;
    }
    for(int i=0;i<(book.size()-1);i++){
        QDate toDate =QDate::fromString(QString::fromStdString(book[i]->gettodate()),"yyyyMMdd");
        QDate fromDate =QDate::fromString(QString::fromStdString(book[i+1]->getfromdate()),"yyyyMMdd");
        if(toDate.daysTo(fromDate)<0){
            return false;
        }


    }
    return true;
}


    std::shared_ptr<Flightbooking> Travel::findfirstflight()
    {
        for(auto& booking:bokingliste){
            if(std::shared_ptr<Flightbooking> flight =std::dynamic_pointer_cast<Flightbooking>(booking)){
                return flight;

            }
        }return nullptr;
    }

    std::shared_ptr<Flightbooking> Travel::findlastflight()
    {


        for(int i=bokingliste.size()-1;i>=0;i-- ){
            if(std::shared_ptr<Flightbooking> flight =std::dynamic_pointer_cast<Flightbooking>(bokingliste[i])){
                return flight;

            }
        }return nullptr;
    }

    bool Travel::checkoverflowhotel()
    {

        std::vector<std::shared_ptr<Booking>>book;
        topologicalsort();
        for(int i=0;i<bokingliste.size();i++){
            if(std::shared_ptr<Rentalcarreservation> rental =std::dynamic_pointer_cast<Rentalcarreservation>(bokingliste[dependencies[i]])){
                continue;
            }


            else{
                book.push_back(bokingliste[dependencies[i]]);
            }
        }
        if(book.size()==0){
            return true;
        }
        for(int i=0;i<book.size()-1;i++){
            QDate toDate =QDate::fromString(QString::fromStdString(book[i]->gettodate()),"yyyyMMdd");
            QDate fromDate =QDate::fromString(QString::fromStdString(book[i+1]->getfromdate()),"yyyyMMdd");
            if(toDate.daysTo(fromDate)<0){
                return false;
            }


        }
        return true;





    }


    std::vector<int> Travel::sortiere()
    {

        std::vector<int> vec;
        DepthFirstSearch(graph,vec);
        return vec;
    }

    void Travel::addBoking(std::shared_ptr<Booking> booking){

        bool found = false;
        for (auto a : bokingliste) {
            if (a->getid() == booking->getid()) {
                found = true;
                break;
            }
        }

        if (!found) {

            bokingliste.push_back(booking);

        }



    }





    long Travel::getcustomerid(){
        return customerID;
    }

    int Travel::gettravelltotalprice()
    {
        int totalprice=0;
        for(int i=0;i<bokingliste.size();i++){
            totalprice= totalprice + bokingliste[i]->d_getprice();

        }
        return totalprice;
    }

    std::shared_ptr<Booking> Travel::findBookingByID(std::string bookingID)
    {
        for (const auto& booking : bokingliste) {
            if (booking->getid() == bookingID)
                return booking;
        }
        return nullptr;
    }


