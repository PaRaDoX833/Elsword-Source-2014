﻿ALTER TABLE [dbo].[GDungeonClear] ADD
CONSTRAINT [FK_GDungeonClear_GUnit] FOREIGN KEY ([UnitUID]) REFERENCES [dbo].[GUnit] ([UnitUID]) ON DELETE CASCADE ON UPDATE CASCADE

