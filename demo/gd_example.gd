extends GDExample

@export var other: OtherClass

func _ready() -> void:
	if !other: return
	self.test(other)
	other.on_changed.connect(on_other_changed)

func _on_position_changed(node: Object, new_pos: Vector2) -> void:
	print("The position of " + node.get_class() + " is now " + str(new_pos))

func on_other_changed() -> void:
	self.test(other)
