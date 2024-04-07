// Fuegen Sie hier Ihre Klassen ein

class Shape {



	public static void main(String[] args){
		Shape shape = new Shape[4];
		shape[0] = new Circle(3, 7, 10);
		shape[1] = new Circle(5, 6, 4);
		shape[2] = new Square(2, 1, 3);
		shape[3] = new Square(7, 8, 3.5);
		
		for (int i = 0; i < shape.length; i++){
			Shape s = shape[i];
			if (s.isInside(4, 5)){
				Out.println("Der Punkt (4, 5) ist in " + s + "enthalten");
			}
		}
	}	
}