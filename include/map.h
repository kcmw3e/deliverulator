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

        Node(double x, double y, std::string name, const std::vector<const Node*> neighbors);
    };

    enum Node_index {
        NI_HH             ,
        NI_PH             ,
        NI_BH             ,
        NI_WEH            ,
        NI_DH             ,
        NI_CFA            ,
        NI_FE             ,
        NI_POS            ,
        NI_MM             ,
        NI_CUC            ,
        NI_PCA            ,
        NI_GHC            ,
        NI_TEP            ,
        NI_HH1            ,
        NI_PH1            ,
        NI_WEH1           ,
        NI_DH1            ,
        NI_BH1            ,
        NI_CFALawn1       ,
        NI_CFALawn2       ,
        NI_CutLLC         ,
        NI_CutLRC         ,
        NI_CFA1           ,
        NI_POS1           ,
        NI_MM1            ,
        NI_CutInter       , // Cut intersection at middle
        NI_CutULC         ,
        NI_PB             , // Pausch Bridge
        NI_CutURC         ,
        NI_CUC1           ,
        NI_PCA1           ,
        NI_PCA2           ,
        NI_Forbes1        , // Intersection point from Forbes to CUC/PCA
        NI_ForbesMoorewood, // Forbes/Morewood intersection
        NI_ForbesTepper   , // Forbes/Tepper Intersection
        NI_TEP1           ,
    };

    static const Node nodes[] = {
        Node{ 77, 173, "HH"  , {&nodes[NI_HH]}},
        Node{100, 128, "PH"  , {&nodes[NI_PH1]}},
        Node{211,  67, "BH"  , {&nodes[NI_BH1]}},
        Node{121, 205, "WEH" , {&nodes[NI_WEH1]}},
        Node{227, 176, "DH"  , {&nodes[NI_DH1]}},
        Node{448, 106, "CFA" , {&nodes[NI_CFA1]}},
        Node{397, 151, "FE"  , {&nodes[NI_CutLLC], &nodes[NI_CutLRC]}},
        Node{547,  58, "POS" , {&nodes[NI_POS1]}},
        Node{595, 134, "MM"  , {&nodes[NI_MM1]}},
        Node{529, 376, "CUC" , {&nodes[NI_CUC1]}},
        Node{392, 312, "PCA" , {&nodes[NI_PCA1]}},
        Node{256, 318, "GHC" , {&nodes[NI_PB]}},
        Node{203, 591, "TEP" , {&nodes[NI_TEP1]}},
        Node{108, 160, "HH1" , {&nodes[NI_HH], &nodes[NI_WEH1], &nodes[NI_PH1]}},
        Node{106, 140, "PH1" , {&nodes[NI_PH], &nodes[NI_HH1], &nodes[NI_BH1]}},
        Node{116, 181, "WEH1", {&nodes[NI_WEH], &nodes[NI_HH1], &nodes[NI_DH1]}},

        Node{
            218, 153, "DH1", {&nodes[NI_DH], &nodes[NI_WEH1], &nodes[NI_BH1], &nodes[NI_CFALawn1]}
        },

        Node{
            220, 110, "BH1", {&nodes[NI_BH], &nodes[NI_PH1], &nodes[NI_DH1], &nodes[NI_CFALawn2]}
        },

        Node{346, 118, "CFALawn1", {&nodes[NI_DH1], &nodes[NI_CFALawn2], &nodes[NI_CutLLC]}},
        Node{335,  78, "CFALawn2", {&nodes[NI_CFALawn1], &nodes[NI_BH1]}},

        Node{
            364, 168, "CutLLC",
            {&nodes[NI_CFALawn1], &nodes[NI_CutInter], &nodes[NI_CutULC], &nodes[NI_CutLRC]}
        },

        Node{
            447, 146, "CutLRC",
            {
                &nodes[NI_CutLLC], &nodes[NI_CutInter], &nodes[NI_CFA1], &nodes[NI_CutURC],
                &nodes[NI_POS1], &nodes[NI_MM1]
            }
        },

        Node{439, 113, "CFA1", {&nodes[NI_CFA], &nodes[NI_CutLRC]}},
        Node{548,  80, "POS1", {&nodes[NI_POS], &nodes[NI_CutLRC], &nodes[NI_MM1]}},
        Node{575, 110, "MM1" , {&nodes[NI_MM], &nodes[NI_POS1], &nodes[NI_CutLRC]}},

        Node{
            408, 213, "CutInter",
            {&nodes[NI_CutLLC], &nodes[NI_CutLRC], &nodes[NI_CutULC], &nodes[NI_CutURC]}
        },

        Node{
            395, 289, "CutULC",
            {&nodes[NI_CutInter], &nodes[NI_CutLLC], &nodes[NI_CutURC], &nodes[NI_CUC1]}
        },

        Node{317, 309, "PB", {&nodes[NI_GHC], &nodes[NI_CutULC]}},

        Node{
            484, 266, "CutURC",
            {&nodes[NI_CutInter], &nodes[NI_CutULC], &nodes[NI_CutLRC], &nodes[NI_CUC1]}
        },

        Node{
            514, 379, "CUC1",
            {&nodes[NI_CUC], &nodes[NI_CutURC], &nodes[NI_PCA2], &nodes[NI_Forbes1]}
        },

        Node{403, 306, "PCA1", {&nodes[NI_PCA], &nodes[NI_CutULC], &nodes[NI_PCA2]}},
        Node{429, 405, "PCA2", {&nodes[NI_PCA1], &nodes[NI_CUC1], &nodes[NI_Forbes1]}},

        Node{
            443, 458, "Forbes1", {&nodes[NI_PCA2], &nodes[NI_CUC1], &nodes[NI_ForbesMoorewood]}
        },

        Node{449, 513, "ForbesMorewood", {&nodes[NI_Forbes1], &nodes[NI_ForbesTepper]}},
        Node{262, 510, "ForbesTepper"  , {&nodes[NI_ForbesMoorewood], &nodes[NI_TEP1]}},
        Node{261, 570, "TEP1"          , {&nodes[NI_TEP], &nodes[NI_ForbesMoorewood]}},
    };

    static const std::vector<const Node*> buildings = {
        &nodes[NI_HH ],
        &nodes[NI_PH ],
        &nodes[NI_BH ],
        &nodes[NI_WEH],
        &nodes[NI_DH ],
        &nodes[NI_CFA],
        &nodes[NI_FE ],
        &nodes[NI_POS],
        &nodes[NI_MM ],
        &nodes[NI_CUC],
        &nodes[NI_PCA],
        &nodes[NI_GHC],
        &nodes[NI_TEP],
    };

    static const std::string map_filename = "resrc/map.png";

    void draw();
    const Node* find_node(std::string name);
};

#endif // !defined(MAP_H)
