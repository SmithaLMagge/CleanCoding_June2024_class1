enum class IconType { Spinner, Slider, Hopper };

class IIcon {
public:
    virtual void Move() = 0;
    virtual void Flair() = 0;
    virtual ~IIcon() = default;
};

class Spinner : public IIcon {
public:
    bool Clockwise;
    bool Expand;

    void Move() override { Spin(); }
    void Flair() override { Spin(); }
private:
    void Spin() { /* Implementation */ }
};

class Slider : public IIcon {
public:
    bool Vertical;
    int Distance;

    void Move() override { Slide(); }
    void Flair() override { Slide(); }
private:
    void Slide() { /* Implementation */ }
};

class Hopper : public IIcon {
public:
    bool Visible;
    int XCoord;
    int YCoord;

    void Move() override { Hop(); }
    void Flair() override { Hop(); }
private:
    void Hop() { /* Implementation */ }
};

class IconFactory {
public:
    static IIcon* CreateIcon(IconType type) {
        switch (type) {
            case IconType::Spinner:
                return new Spinner();
            case IconType::Slider:
                return new Slider();
            case IconType::Hopper:
                return new Hopper();
            default:
                throw std::invalid_argument("Invalid Icon Type");
        }
    }
};
