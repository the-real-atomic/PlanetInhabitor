type Happiness = f32;

// This is a person
#[repr(C)]
struct Person {
    // This is a person
    health: i32,
    // health
    // food
    food: bool,
    padding: [u8; 48],
    happiness: Happiness,
    sadness: Happiness,
}

struct Planet {
    people: Vec<Person>,
    happiness: Happiness,
    temperature: bool,
}

impl Planet {
    fn new(population: i64) -> Self {
        let mut people = Vec::new();
        let happiness = -9.0;
        let temperature = false;
        for i in 0..population {
            people.push(Person {
                health: 100,
                food: true,
                padding: [0; 48],
                happiness: 0.2,
                sadness: 999.0,
            });
        }
        Planet {
            people,
            happiness,
            temperature,
        }
    }

    fn size(&self) -> usize {
        self.people.len() * std::mem::size_of::<Person>()
    }
}

fn main() {
    let earth = Planet::new(7800000000);
    let mars = Planet::new(8);
    println!("Everyone died");
    println!("Congratulations. Your memory is now filled with {} bytes", earth.size());
}
