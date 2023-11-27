// ============================================================================================== //
// Primary author: Eric Zhao
//
// CMU's campus map is represented as a series of connected nodes (e.g. a graph). Every intersection
// and building is considered a node as might be expected, but for the sake of simplicity in terms
// of moving a robot along the screen, there are also nodes for the turns in a path. This way a
// robot only needs to know the path it is on between two nodes, and it can follow along the screen
// by simply drawing itself somewhere on the line between these paths, and it can follow turns by
// adjusting the nodes it is between.
//
// There is no real distinction between buildings/points of interest and general nodes (e.g. a node
// at an intersection or curve) besides the static member within the Map class that identifies them.
// ============================================================================================== //

#if !defined(MAP_H)
#define MAP_H

#include <vector>
#include <string>

namespace Map {
    struct Node {
        static constexpr double rad = 10.0;

        const double x;
        const double y;
        const std::string name;
        const std::vector<const Node*> neighbors;

        Node(double x, double y, std::string name);
        Node(const Node& node, const std::vector<const Node*> neightbors);
    };

    static Node HH{77, 173, "HH"};
    static Node PH{100, 128, "PH"};
    static Node BH{211, 67, "BH"};
    static Node WEH{121, 205, "WEH"};
    static Node DH{227, 176, "DH"};
    static Node CFA{448, 106, "CFA"};
    static Node FE{397, 151, "FE"};
    static Node POS{547, 58, "POS"};
    static Node MM{595, 134, "MM"};
    static Node CUC{529, 376, "CUC"};
    static Node PCA{392, 312, "PCA"};
    static Node GHC{256, 318, "GHC"};
    static Node TEP{203, 591, "TEP"};

    static Node HH1{108, 160, "HH1"};
    static Node PH1{106, 140, "PH1"};
    static Node WEH1{116, 181, "WEH1"};
    static Node DH1{218, 153, "DH1"};
    static Node BH1{220, 110, "BH1"};
    static Node CFALawn1{346, 118, "CFALawn1"};
    static Node CFALawn2{335, 78, "CFALawn2"};
    static Node CutLLC{364, 168, "CutLLC"};
    static Node CutLRC{447, 146, "CutLRC"};
    static Node CFA1{439, 113, "CFA1"};
    static Node POS1{548, 80, "POS1"};
    static Node MM1{575, 110, "MM1"};
    static Node CutInter{408, 213, "CutInter"}; // Cut intersection at middle
    static Node CutULC{395, 289, "CutULC"};
    static Node PB{317, 309, "PB"}; // Pausch Bridge
    static Node CutURC{484, 266, "CutURC"};
    static Node CUC1{514, 379, "CUC1"};
    static Node PCA1{403, 306, "PCA1"};
    static Node PCA2{429, 405, "PCA2"};
    static Node Forbes1{443, 458, "Forbes1"}; // Intersection point from Forbes to CUC/PCA
    static Node ForbesMorewood{449, 513, "ForbesMorewood"}; // Forbes/Morewood intersection
    static Node ForbesTepper{262, 510, "ForbesTepper"}; // Forbes/Tepper Intersection
    static Node TEP1{261, 570, "TEP1"};

    static const std::vector<Node> nodes = {
        Node(HH,  {&HH1}),
        Node(PH,  {&PH1}),
        Node(BH,  {&BH1}),
        Node(WEH, {&WEH1}),
        Node(DH,  {&DH1}),
        Node(CFA, {&CFA1}),
        Node(FE,  {&CutLLC, &CutLRC}),
        Node(POS, {&POS1}),
        Node(MM,  {&MM1}),
        Node(CUC, {&CUC1}),
        Node(PCA, {&PCA1}),
        Node(GHC, {&PB}),
        Node(TEP, {&TEP1}),

        Node(HH1,            {&HH, &WEH1, &PH1}),
        Node(PH1,            {&PH, &HH1, &BH1}),
        Node(WEH1,           {&WEH, &HH1, &DH1}),
        Node(DH1,            {&DH, &WEH1, &BH1, &CFALawn1}),
        Node(BH1,            {&BH, &PH1, &DH1, &CFALawn2}),
        Node(CFALawn1,       {&DH1, &CFALawn2, &CutLLC}),
        Node(CFALawn2,       {&CFALawn1, &BH1}),
        Node(CutLLC,         {&CFALawn1, &CutInter, &CutULC, &CutLRC}),
        Node(CutLRC,         {&CutLLC, &CutInter, &CFA1, &CutURC, &POS1, &MM1}),
        Node(CFA1,           {&CFA, &CutLRC}),
        Node(POS1,           {&POS, &CutLRC, &MM1}),
        Node(MM1,            {&MM, &POS1, &CutLRC}),
        Node(CutInter,       {&CutLLC, &CutLRC, &CutULC, &CutURC}),
        Node(CutULC,         {&CutInter, &CutLLC, &CutURC, &PB, &PCA1}),
        Node(PB,             {&GHC, &CutULC}),
        Node(CutURC,         {&CutInter, &CutULC, &CutLRC, &CUC1}),
        Node(CUC1,           {&CUC, &CutURC, &PCA2, &Forbes1}),
        Node(PCA1,           {&PCA, &CutULC, &PCA2}),
        Node(PCA2,           {&PCA1, &CUC1, &Forbes1}),
        Node(Forbes1,        {&PCA2, &CUC1, &ForbesMorewood}),
        Node(ForbesMorewood, {&Forbes1, &ForbesTepper}),
        Node(ForbesTepper,   {&ForbesMorewood, &TEP1}),
        Node(TEP1,           {&TEP, &ForbesMorewood}),
    };

    static const std::vector<const Node*> buildings = {
        &nodes[ 0], // HH
        &nodes[ 1], // PH
        &nodes[ 2], // BH
        &nodes[ 3], // WEH
        &nodes[ 4], // DH
        &nodes[ 5], // CFA
        &nodes[ 6], // FE
        &nodes[ 7], // POS
        &nodes[ 8], // MM
        &nodes[ 9], // CUC
        &nodes[10], // PCA
        &nodes[11], // GHC
        &nodes[12], // TEP
    };

    static const std::string map_filename = "resrc/map.png";

    void draw();
    const Node* find_node(std::string name);
};

#endif // !defined(MAP_H)
