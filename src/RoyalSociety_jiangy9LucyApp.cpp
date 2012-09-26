#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"
#include "RoyalSociety_jiangy9Lucy.h"
#include "Shape.h"
#include "Circle.h"
#include "rectangle.h"
#include "HorizonalLine.h"
#include "VerticalLine.h"
#include "Diagonal.h"
#include "Flower.h"
#include "cinder/gl/TextureFont.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class RoyalSociety_jiangy9LucyApp : public AppBasic {
 public:
	void setup();
	void mouseDown( MouseEvent event );
	void keyDown( KeyEvent event );
	void update();
	void draw();
	void prepareSettings(Settings* settings);

  private:
	static const int windowWidth = 1024;
	static const int windowHeight = 1024;
	node* first_item;
	node* currentNode;
	Surface* mySurface;

	rectangle* sky;
	rectangle* grass;
	rectangle* river;
	
	Circle* sun;
	
	HorizonalLine* lineOne;
	HorizonalLine* lineTwo;
	
	VerticalLine* lineThree;
	VerticalLine* lineFour;
	
	Diagonal* line_1;
	Diagonal* line_2;
	Diagonal* line_3;
	Diagonal* line_4;
	Diagonal* line_5;
	Diagonal* line_6;
	Diagonal* line_7;
	Diagonal* line_8;
	Diagonal* line_9;
	Diagonal* line_10;
	Diagonal* line_11;

	Diagonal* line_12;
	Diagonal* line_13;
	Diagonal* line_14;
	Diagonal* line_15;
	Diagonal* line_16;
	Diagonal* line_17;
	Diagonal* line_18;
	Diagonal* line_19;
	Diagonal* line_20;
	Diagonal* line_21;
	Diagonal* line_22;

	Diagonal* line_23;
	Diagonal* line_24;
	Diagonal* line_25;
	Diagonal* line_26;
	Diagonal* line_27;
	Diagonal* line_28;
	Diagonal* line_29;
	Diagonal* line_30;
	Diagonal* line_31;
	Diagonal* line_32;
	Diagonal* line_33;

	Diagonal* line_34;
	Diagonal* line_35;
	Diagonal* line_36;
	Diagonal* line_37;
	Diagonal* line_38;
	Diagonal* line_39;
	Diagonal* line_40;
	Diagonal* line_41;
	Diagonal* line_42;
	Diagonal* line_43;
	Diagonal* line_44;
	
	Flower* flower1;
	Flower* flower2;
	Flower* flower3;
	Flower* flower4;
	Flower* flower5;
	Flower* flower6;
	Flower* flower7;
	Flower* flower8;

	Font mFont;
	Font mFont2;
	gl::TextureFontRef	mTextureFont;
	gl::TextureFontRef	mTextureFont2;

	int press;
	float trans;
	int click;
	Color8u addFlowerColor;
	int reverseObject;
};

void insertAfter(node* position, Shape* shape){
	node* my_node = new node;
	my_node->data = shape;
	my_node->next = position->next;
	position->next = my_node;
	my_node->previous = position->previous;
	position->previous = my_node;
}

// try to reverse the linked list --> implement main goal E

/*You mentioned in your final commit that the reverse method was not working. This is both true and kinda false. 
The actual code in the reverse method that you have is completely right, it looks almost exactly like my code. After doing some debugging
I found the real issue behind this problem. The root of the problem is coming from your insert after method. When you first declare your
"first_item" node* pointer it points back to itself (which is what you want), but when you are creating more nodes, those nodes are also pointing back
on themselves, not to the other nodes. This is making it so that your list is not really connected since each node is really only connected
to itself. That IS the root of the problem you are having, however, after trying for a while to fix that, I kept on crashing the program. I can't
figure out exactly how to fix it, but the problem is definitely with the pointers not going to the next node. 

If you are interested in seeing what I'm talking about for yourself, place some breakpoints along each line of the insertAfter method and press
F5 and watch position(next), position(previous) and position as well as my_node. 

I tried to make the fixes but I just couldn't figure out exactly how to do them, sorry. Hope some of this explaination helped a little though. 

*/
void reverse(node* sentinel){
	node* cur = sentinel;
    do {
        node* temp = cur->next;
        cur->next = cur->previous;
        cur->previous = temp;
		cur = cur->previous;
    } while(cur != sentinel);
}

void RoyalSociety_jiangy9LucyApp::prepareSettings(Settings* settings){
	settings->setWindowSize(windowWidth, windowHeight);
}

void RoyalSociety_jiangy9LucyApp::setup()
{
	mySurface = new Surface(windowWidth, windowHeight, true);

	sky = new rectangle();
	grass = new rectangle();
	river = new rectangle();
	
	sun = new Circle();

	lineOne = new HorizonalLine();
	lineTwo = new HorizonalLine();
	lineThree = new VerticalLine();
	lineFour = new VerticalLine();

	line_1 = new Diagonal();
	line_2 = new Diagonal();
	line_3 = new Diagonal();
	line_4 = new Diagonal();
	line_5 = new Diagonal();
	line_6 = new Diagonal();
	line_7 = new Diagonal();
	line_8 = new Diagonal();
	line_9 = new Diagonal();
	line_10 = new Diagonal();
	line_11 = new Diagonal();

	line_12 = new Diagonal();
	line_13 = new Diagonal();
	line_14 = new Diagonal();
	line_15 = new Diagonal();
	line_16 = new Diagonal();
	line_17 = new Diagonal();
	line_18 = new Diagonal();
	line_19 = new Diagonal();
	line_20 = new Diagonal();
	line_21 = new Diagonal();
	line_22 = new Diagonal();

	line_23 = new Diagonal();
	line_24 = new Diagonal();
	line_25 = new Diagonal();
	line_26 = new Diagonal();
	line_27 = new Diagonal();
	line_28 = new Diagonal();
	line_29 = new Diagonal();
	line_30 = new Diagonal();
	line_31 = new Diagonal();
	line_32 = new Diagonal();
	line_33 = new Diagonal();

	line_34 = new Diagonal();
	line_35 = new Diagonal();
	line_36 = new Diagonal();
	line_37 = new Diagonal();
	line_38 = new Diagonal();
	line_39 = new Diagonal();
	line_40 = new Diagonal();
	line_41 = new Diagonal();
	line_42 = new Diagonal();
	line_43 = new Diagonal();
	line_44 = new Diagonal();

	flower1 = new Flower();
	flower2 = new Flower();
	flower3 = new Flower();
	flower4 = new Flower();
	flower5 = new Flower();
	flower6 = new Flower();
	flower7 = new Flower();
	flower8 = new Flower();

	//set up the first item of linked list
	first_item = new node;
	first_item->data = NULL;
	first_item->next = first_item;
	first_item->previous = first_item;

	currentNode = first_item->next;
	press = 0;

	gl::enableAlphaBlending();
	trans = 0.0f;

	click = 0;
	addFlowerColor = Color8u(255,174,201);

	reverseObject = 0;

	uint8_t* dataArray = (*mySurface).getData();

	//add objects into linked list --> implement main goals A
	sky->setRectangle(dataArray,0,0,windowWidth,400,1.0f,Color8u(146,227,241));        // sky
	insertAfter(first_item->previous,sky);
	grass->setRectangle(dataArray,0,401,windowWidth,500,1.0f,Color8u(33,237,64));      // grass
	insertAfter(first_item->previous,grass);

	//use transparency to build a color-changing river --> implement main goals G
	river->setRectangle(dataArray,0,650,windowWidth,windowHeight,sin(trans),Color8u(48,57,177));       // river
	insertAfter(first_item->previous,river);

	sun->setCircle(dataArray,40.0f,100.0f,100.0f,Color8u(241,3,3));              // sun
	insertAfter(first_item->previous,sun);
	
	lineOne->set(dataArray,10,50,100,Color8u(255,127,39));
	insertAfter(first_item->previous,lineOne);
	lineTwo->set(dataArray,150,190,100,Color8u(255,127,39));
	insertAfter(first_item->previous,lineTwo);

	lineThree->set(dataArray,10,50,100,Color8u(255,127,39));
	insertAfter(first_item->previous,lineThree);
	lineFour->set(dataArray,150,190,100,Color8u(255,127,39));
	insertAfter(first_item->previous,lineFour);

	
	line_1->set(dataArray,30,30,60,60,Color8u(255,127,39));
	insertAfter(first_item->previous,line_1);
	line_2->set(dataArray,30,31,60,61,Color8u(255,127,39));
	insertAfter(first_item->previous,line_2);
	line_3->set(dataArray,30,32,60,62,Color8u(255,127,39));
	insertAfter(first_item->previous,line_3);
	line_4->set(dataArray,30,33,60,63,Color8u(255,127,39));
	insertAfter(first_item->previous,line_4);
	line_5->set(dataArray,30,34,60,64,Color8u(255,127,39));
	insertAfter(first_item->previous,line_5);
	line_6->set(dataArray,30,35,60,65,Color8u(255,127,39));
	insertAfter(first_item->previous,line_6);
	line_7->set(dataArray,30,36,60,66,Color8u(255,127,39));
	insertAfter(first_item->previous,line_7);
	line_8->set(dataArray,30,37,60,67,Color8u(255,127,39));
	insertAfter(first_item->previous,line_8);
	line_9->set(dataArray,30,38,60,68,Color8u(255,127,39));
	insertAfter(first_item->previous,line_9);
	line_10->set(dataArray,30,39,60,69,Color8u(255,127,39));
	insertAfter(first_item->previous,line_10);
	line_11->set(dataArray,30,40,60,70,Color8u(255,127,39));
	insertAfter(first_item->previous,line_11);

	line_12->set(dataArray,135,135,165,165,Color8u(255,127,39));
	insertAfter(first_item->previous,line_12);
	line_13->set(dataArray,135,136,165,166,Color8u(255,127,39));
	insertAfter(first_item->previous,line_13);
	line_14->set(dataArray,135,137,165,167,Color8u(255,127,39));
	insertAfter(first_item->previous,line_14);
	line_15->set(dataArray,135,138,165,168,Color8u(255,127,39));
	insertAfter(first_item->previous,line_15);
	line_16->set(dataArray,135,139,165,169,Color8u(255,127,39));
	insertAfter(first_item->previous,line_16);
	line_17->set(dataArray,135,140,165,170,Color8u(255,127,39));
	insertAfter(first_item->previous,line_17);
	line_18->set(dataArray,135,141,165,171,Color8u(255,127,39));
	insertAfter(first_item->previous,line_18);
	line_19->set(dataArray,135,142,165,172,Color8u(255,127,39));
	insertAfter(first_item->previous,line_19);
	line_20->set(dataArray,135,143,165,173,Color8u(255,127,39));
	insertAfter(first_item->previous,line_20);
	line_21->set(dataArray,135,144,165,174,Color8u(255,127,39));
	insertAfter(first_item->previous,line_21);
	line_22->set(dataArray,135,145,165,175,Color8u(255,127,39));
	insertAfter(first_item->previous,line_22);


	line_23->set(dataArray,35,165,65,135,Color8u(255,127,39));
	insertAfter(first_item->previous,line_23);
	line_24->set(dataArray,35,166,65,136,Color8u(255,127,39));
	insertAfter(first_item->previous,line_24);
	line_25->set(dataArray,35,167,65,137,Color8u(255,127,39));
	insertAfter(first_item->previous,line_25);
	line_26->set(dataArray,35,168,65,138,Color8u(255,127,39));
	insertAfter(first_item->previous,line_26);
	line_27->set(dataArray,35,169,65,139,Color8u(255,127,39));
	insertAfter(first_item->previous,line_27);
	line_28->set(dataArray,35,170,65,140,Color8u(255,127,39));
	insertAfter(first_item->previous,line_28);
	line_29->set(dataArray,35,171,65,141,Color8u(255,127,39));
	insertAfter(first_item->previous,line_29);
	line_30->set(dataArray,35,172,65,142,Color8u(255,127,39));
	insertAfter(first_item->previous,line_30);
	line_31->set(dataArray,35,173,65,143,Color8u(255,127,39));
	insertAfter(first_item->previous,line_31);
	line_32->set(dataArray,35,174,65,144,Color8u(255,127,39));
	insertAfter(first_item->previous,line_32);
	line_33->set(dataArray,35,175,65,145,Color8u(255,127,39));
	insertAfter(first_item->previous,line_33);

	line_34->set(dataArray,135,60,165,30,Color8u(255,127,39));
	insertAfter(first_item->previous,line_34);
	line_35->set(dataArray,135,61,165,31,Color8u(255,127,39));
	insertAfter(first_item->previous,line_35);
	line_36->set(dataArray,135,62,165,32,Color8u(255,127,39));
	insertAfter(first_item->previous,line_36);
	line_37->set(dataArray,135,63,165,33,Color8u(255,127,39));
	insertAfter(first_item->previous,line_37);
	line_38->set(dataArray,135,64,165,34,Color8u(255,127,39));
	insertAfter(first_item->previous,line_38);
	line_39->set(dataArray,135,65,165,35,Color8u(255,127,39));
	insertAfter(first_item->previous,line_39);
	line_40->set(dataArray,135,66,165,36,Color8u(255,127,39));
	insertAfter(first_item->previous,line_40);
	line_41->set(dataArray,135,67,165,37,Color8u(255,127,39));
	insertAfter(first_item->previous,line_41);
	line_42->set(dataArray,135,68,165,38,Color8u(255,127,39));
	insertAfter(first_item->previous,line_42);
	line_43->set(dataArray,135,69,165,39,Color8u(255,127,39));
	insertAfter(first_item->previous,line_43);
	line_44->set(dataArray,135,70,165,40,Color8u(255,127,39));
	insertAfter(first_item->previous,line_44);

	//draw flowers in different colors from deep to light --> implement main goal H
	flower1->set(dataArray,490.0f,100.0f,Color8u(237,28,36));
	insertAfter(first_item->previous,flower1);
	flower2->set(dataArray,560.0f,150.0f,Color8u(240,66,74));
	insertAfter(first_item->previous,flower2);
	flower3->set(dataArray,600.0f,200.0f,Color8u(242,94,101));
	insertAfter(first_item->previous,flower3);
	flower4->set(dataArray,560.0f,250.0f,Color8u(244,117,123));
	insertAfter(first_item->previous,flower4);
	flower5->set(dataArray,490.0f,300.0f,Color8u(245,139,145));
	insertAfter(first_item->previous,flower5);
	flower6->set(dataArray,420.0f,250.0f,Color8u(248,165,169));
	insertAfter(first_item->previous,flower6);
	flower7->set(dataArray,350.0f,200.0f,Color8u(250,190,193));
	insertAfter(first_item->previous,flower7);
	flower8->set(dataArray,420.0f,150.0f,Color8u(252,220,222));
	insertAfter(first_item->previous,flower8);
}

//When user presses "/" key, display introduction of application --> implement main goal B
void RoyalSociety_jiangy9LucyApp::keyDown( KeyEvent event ){
	if(event.getChar()=='/')
		press++;
	else if(event.getChar()=='r')
		reverseObject++;
}

//When user clicks left button of mouse, draw flowers that painted in different color--> implement stretch goal J
void RoyalSociety_jiangy9LucyApp::mouseDown( MouseEvent event )
{
	gl::enableAlphaBlending();
	if(event.isLeftDown()){
		Flower* addFlower = new Flower();
		addFlower->set((*mySurface).getData(),(float)event.getX(),(float)event.getY(), addFlowerColor);
		insertAfter(first_item->previous,addFlower);
		click++;
	}
}

void RoyalSociety_jiangy9LucyApp::update()
{
	gl::enableAlphaBlending();
	uint8_t* dataArray = (*mySurface).getData();
	// try to reverse the linked list --> implement main goal E
	if(reverseObject%2==1){
		reverse(first_item);
	}

	//use transparency to build color-changing river --> implement main goal G
	river->setRectangle(dataArray,0,650,windowWidth,windowHeight,sin(trans),Color8u(48,57,177));       // river
	insertAfter(first_item->previous,river);
	trans = trans + 0.01f;

	//Change flowers' color
	if(click!=0){
		if(click%3==1)
			addFlowerColor = Color8u(237,28,36);
		else if(click%3==2)
			addFlowerColor = Color8u(255,242,0);
		else
			addFlowerColor = Color8u(163,73,164);
	}

	currentNode = first_item->next;
	while(currentNode!=first_item){
		currentNode->data->draw();
		currentNode = currentNode->next;
	}

}

void RoyalSociety_jiangy9LucyApp::draw()
{
	gl::draw(*mySurface);

	// display message to explain the controls of my application by "?"-> implement main goal 2 
	if(press%2==1){
		mFont = Font( "Times New Roman", 24 );
		mTextureFont = gl::TextureFont::create( mFont );
		std::string str("Welcome! Press '/' key can open and close this introduction. Use mouse clicking to create flowers with 3 different colors in gray rectangle between grass and river!");
		gl::color( Color8u( 0,0,0 ) );
		gl::enableAlphaBlending();
		Rectf boundsRect( 40, mTextureFont->getAscent() + 40, getWindowWidth() - 40, getWindowHeight() - 40 );
		mTextureFont->drawStringWrapped( str, boundsRect );
		gl::color(Color8u(255,255,255));
	}

}

CINDER_APP_BASIC( RoyalSociety_jiangy9LucyApp, RendererGl )
