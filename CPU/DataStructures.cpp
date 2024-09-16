//
// Created by dominykas on 15-11-23.
//

#include "DataStructures.h"

void Node::Expand(){
    nodes.NE = new Node(glm::vec4(origin.x-origin.w/2, origin.y+origin.w/2, 0, origin.w/2));
    nodes.NW = new Node(glm::vec4(origin.x+origin.w/2, origin.y+origin.w/2, 0, origin.w/2));
    nodes.SE = new Node(glm::vec4(origin.x-origin.w/2, origin.y-origin.w/2, 0, origin.w/2));
    nodes.SW = new Node(glm::vec4(origin.x+origin.w/2, origin.y-origin.w/2, 0, origin.w/2));
}
void Node::Insert(glm::vec4 to_insert){
    if(to_insert.x < to_insert.x-origin.w || to_insert.x > origin.x +origin.w || to_insert.y < origin.y-origin.w || to_insert.y > origin.y +origin.w)return;
    if(body.w == 0){
        body = to_insert;
        return;
    }
    if(end){
        Expand();
    }
    nodes.SW->Insert(to_insert);
    nodes.SE->Insert(to_insert);
    nodes.NE->Insert(to_insert);
    nodes.NW->Insert(to_insert);
}

Node::Node(glm::vec4 origin){
   this->origin = origin;
}
