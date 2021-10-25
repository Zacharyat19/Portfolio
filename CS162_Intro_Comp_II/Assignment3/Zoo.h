#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "Monkey.h"
#include "Sea_otter.h"
#include "Sloth.h"

class Zoo {
    private:
        int bank;
        int month;
        int num_monkeys;
        int num_sea_otters;
        int num_sloths;
        int num_snakes;
        Monkey *monkeys;
        Sea_otter *sea_otters;
        Sloth *sloths;
    public:
        Zoo();
        Zoo(const Zoo &);
        Zoo &operator=(const Zoo &);
        ~Zoo();

        int get_bank() const;
        int get_month() const;
        int get_num_monkeys() const;
        int get_num_sea_otters() const;
        int get_num_sloths() const;
        Monkey *get_monkeys() const;
        Sea_otter *get_sea_otter() const;
        Sloth *get_sloths() const;


        void set_bank(int);
        void set_month(int);
        void set_num_monkeys(int);
        void set_num_sea_otters(int);
        void set_num_sloths(int);
        void set_monkeys(Monkey *);
        void set_sea_otter(Sea_otter *);
        void set_sloths(Sloth *);

        void add_monkey(Monkey monkey_to_add);
        void add_sea_otter(Sea_otter otter_to_add);
        void add_sloth(Sloth slot_to_add);
        void remove_monkey(int index_to_remove);
        void remove_sea_otter(int index_to_remove);
        void remove_sloth(int index_to_remove);
        void buy_monkey(int );
        void buy_sea_otter(int );
        void buy_sloth(int );
        void increase_age();
        Zoo& operator++();
        void event();
        void sick_monkey();
        void sick_sea_otter();
        void sick_sloth();
        void monkey_babies();
        void sea_otter_babies();
        void sloth_babies();
        void monkey_revenue();
        void sea_otter_revenue();
        void sloth_revenue();
        void extra_revenue();
        void sell_monkey();
        void sell_sea_otter();
        void sell_sloth();
        void display_monkeys();
        void display_sea_otters();
        void display_sloths();
        void food(int &);
        void monkey_food(int &, int &);
        void sea_otter_food(int &, int &);
        void sloth_food(int &, int &);
        void buy_sell();
};

#endif